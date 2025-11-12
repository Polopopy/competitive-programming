#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c;
    if (!(cin >> r >> c)) return 0;
    vector<string> g(r);
    for (int i = 0; i < r; ++i) cin >> g[i];

    auto inb = [&](int x, int y){ return 0 <= x && x < r && 0 <= y && y < c; };

    // Identify river cells and index them
    auto isRiverChar = [](char ch){
        return ch=='^' || ch=='v' || ch=='<' || ch=='>';
    };
    vector<vector<int>> id(r, vector<int>(c, -1));
    vector<pair<int,int>> nodes;
    nodes.reserve(r*c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (isRiverChar(g[i][j])) {
                id[i][j] = (int)nodes.size();
                nodes.emplace_back(i, j);
            }
    int n = (int)nodes.size();

    // Build next pointer per river node: to another river node or -1 (terminal)
    vector<int> nxt(n, -1);
    for (int u = 0; u < n; ++u) {
        auto [i, j] = nodes[u];
        int di = 0, dj = 0;
        switch (g[i][j]) {
            case '^': di = -1; dj = 0; break;
            case 'v': di =  1; dj = 0; break;
            case '<': di = 0; dj = -1; break;
            case '>': di = 0; dj =  1; break;
        }
        int ni = i + di, nj = j + dj;
        if (inb(ni, nj) && id[ni][nj] != -1) nxt[u] = id[ni][nj];
        else nxt[u] = -1; // to land or out of bounds
    }

    // Build SCCs of functional graph:
    // Each non-cycle node is its own SCC; each cycle becomes one SCC.
    vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=done
    vector<int> scc_id(n, -1);
    vector<char> is_cycle_scc; // per SCC
    is_cycle_scc.reserve(n);
    vector<int> instack_index(n, -1);
    int scc_cnt = 0;

    for (int start = 0; start < n; ++start) {
        if (state[start] != 0) continue;
        vector<int> path;
        int u = start;
        while (u != -1 && state[u] == 0) {
            state[u] = 1;
            instack_index[u] = (int)path.size();
            path.push_back(u);
            u = nxt[u];
        }
        if (u == -1 || (u != -1 && state[u] == 2)) {
            // No new cycle: every node in path becomes its own SCC
            for (int k = (int)path.size() - 1; k >= 0; --k) {
                int v = path[k];
                scc_id[v] = scc_cnt++;
                is_cycle_scc.push_back(false);
                state[v] = 2;
                instack_index[v] = -1;
            }
        } else {
            // Found a cycle within current path
            int pos = instack_index[u]; // start index of cycle in path
            int cyc_scc = scc_cnt++;
            is_cycle_scc.push_back(true);
            // Assign cycle nodes
            for (int k = pos; k < (int)path.size(); ++k) {
                int v = path[k];
                scc_id[v] = cyc_scc;
                state[v] = 2;
                instack_index[v] = -1;
            }
            // Assign tail nodes as singleton SCCs
            for (int k = pos - 1; k >= 0; --k) {
                int v = path[k];
                scc_id[v] = scc_cnt++;
                is_cycle_scc.push_back(false);
                state[v] = 2;
                instack_index[v] = -1;
            }
        }
    }

    // Successor SCC per SCC (for cycles or terminal, successor = -1)
    vector<int> succ_scc(scc_cnt, -1);
    for (int u = 0; u < n; ++u) {
        int su = scc_id[u];
        if (is_cycle_scc[su]) continue; // self-contained
        int v = nxt[u];
        if (v == -1) { succ_scc[su] = -1; }
        else { succ_scc[su] = scc_id[v]; }
    }

    // Reverse forest: edges from an SCC to those that flow into it
    vector<vector<int>> rev(scc_cnt);
    for (int u = 0; u < scc_cnt; ++u) {
        int v = succ_scc[u];
        if (v != -1) rev[v].push_back(u);
    }

    // Euler tour (iterative) on reverse forest to get tin/tout so that
    // the reverse subtree of X is a contiguous interval [tin[X], tout[X]].
    vector<int> tin(scc_cnt, 0), tout(scc_cnt, 0);
    int timer = 0;

    auto dfs_iter = [&](int root){
        // stack of (node, next-child-index)
        vector<pair<int,int>> st;
        st.emplace_back(root, -1); // -1 means entry not processed yet
        while (!st.empty()) {
            auto &[u, it] = st.back();
            if (it == -1) {
                tin[u] = ++timer;
                it = 0;
            }
            if (it < (int)rev[u].size()) {
                int v = rev[u][it++];
                st.emplace_back(v, -1);
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
    };

    // Start DFS from all roots (SCCs with no successor)
    for (int s = 0; s < scc_cnt; ++s)
        if (succ_scc[s] == -1)
            dfs_iter(s);

    // Prepare a difference array over Euler order to do many subtree adds
    vector<int> diff(timer + 3, 0);

    auto is_ancestor = [&](int a, int b){
        // In the reverse forest sense: a is ancestor of b
        return tin[a] <= tin[b] && tin[b] <= tout[a];
    };

    // For every sightseeing spot, collect adjacent SCCs,
    // remove any SCC that reaches another adjacent SCC (keep downstream-most),
    // then add +1 to each remaining SCC's reverse subtree interval.
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] != '#') continue;
            int nei[4][2] = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
            int sccs[4];
            int m = 0;
            for (int d = 0; d < 4; ++d) {
                int ni = nei[d][0], nj = nei[d][1];
                if (!inb(ni, nj)) continue;
                int nid = id[ni][nj];
                if (nid == -1) continue;
                int sid = scc_id[nid];
                bool dup = false;
                for (int t = 0; t < m; ++t) if (sccs[t] == sid) { dup = true; break; }
                if (!dup) sccs[m++] = sid;
            }
            if (m == 0) continue;

            // Mark which to keep: remove any a that has some b with b ancestor of a (downstream of a)
            vector<char> keep(m, 1);
            for (int a = 0; a < m; ++a) {
                for (int b = 0; b < m; ++b) if (a != b) {
                    if (is_ancestor(sccs[b], sccs[a])) {
                        // sccs[a] reaches sccs[b] along successors, so drop a (upstream)
                        keep[a] = 0;
                        break;
                    }
                }
            }
            for (int t = 0; t < m; ++t) if (keep[t]) {
                int su = sccs[t];
                int L = tin[su], R = tout[su];
                diff[L] += 1;
                diff[R+1] -= 1;
            }
        }
    }

    // Prefix sum over Euler order gives count per SCC
    vector<int> val(timer + 3, 0);
    int cur = 0;
    for (int t = 1; t <= timer; ++t) {
        cur += diff[t];
        val[t] = cur;
    }
    int ans = 0;
    for (int s = 0; s < scc_cnt; ++s) {
        ans = max(ans, val[tin[s]]);
    }
    cout << ans << "\n";
    return 0;
}
