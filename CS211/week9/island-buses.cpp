#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n=0): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a; if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> maps;
    vector<string> cur;
    string line;

    while (getline(cin, line)) {
        if (!line.empty() && line.back()=='\r') line.pop_back();
        if (line.empty()) {
            if (!cur.empty()) { maps.push_back(cur); cur.clear(); }
        } else {
            cur.push_back(line);
        }
    }
    if (!cur.empty()) maps.push_back(cur);

    auto inb = [](int r,int c,int R,int C){ return r>=0 && r<R && c>=0 && c<C; };
    const int dr[4]={-1,1,0,0};
    const int dc[4]={0,0,-1,1};

    for (size_t mi = 0; mi < maps.size(); ++mi) {
        const auto& grid = maps[mi];
        int R = (int)grid.size();
        int C = R ? (int)grid[0].size() : 0;

        // Label islands (# or X) by 4-neighbor BFS
        vector<vector<int>> id(R, vector<int>(C, -1));
        int islands = 0;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if (id[r][c]==-1 && (grid[r][c]=='#' || grid[r][c]=='X')){
                    int curId = islands++;
                    queue<pair<int,int>> q;
                    id[r][c]=curId; q.push({r,c});
                    while(!q.empty()){
                        auto [rr,cc]=q.front(); q.pop();
                        for(int k=0;k<4;k++){
                            int nr=rr+dr[k], nc=cc+dc[k];
                            if(inb(nr,nc,R,C) && id[nr][nc]==-1 &&
                               (grid[nr][nc]=='#' || grid[nr][nc]=='X')){
                                id[nr][nc]=curId;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        DSU dsu(islands);
        int bridges = 0;

        // Horizontal B-runs with X at both ends
        for(int r=0;r<R;r++){
            for(int c=0;c<C;){
                if (grid[r][c]=='B' && (c==0 || grid[r][c-1]!='B')){
                    int e=c;
                    while(e+1<C && grid[r][e+1]=='B') e++;
                    bool left_ok = (c-1>=0 && grid[r][c-1]=='X');
                    bool right_ok = (e+1<C && grid[r][e+1]=='X');
                    if (left_ok && right_ok){
                        int a=id[r][c-1], b=id[r][e+1];
                        if (a!=-1 && b!=-1){
                            bridges++;
                            dsu.unite(a,b);
                        }
                    }
                    c=e+1;
                } else c++;
            }
        }

        // Vertical B-runs with X at both ends
        for(int c=0;c<C;c++){
            for(int r=0;r<R;){
                if (grid[r][c]=='B' && (r==0 || grid[r-1][c]!='B')){
                    int e=r;
                    while(e+1<R && grid[e+1][c]=='B') e++;
                    bool up_ok = (r-1>=0 && grid[r-1][c]=='X');
                    bool down_ok = (e+1<R && grid[e+1][c]=='X');
                    if (up_ok && down_ok){
                        int a=id[r-1][c], b=id[e+1][c];
                        if (a!=-1 && b!=-1){
                            bridges++;
                            dsu.unite(a,b);
                        }
                    }
                    r=e+1;
                } else r++;
            }
        }

        int buses = 0;
        for(int i=0;i<islands;i++) if (dsu.find(i)==i) buses++;

        cout << "Map " << (mi+1) << "\n";
        cout << "islands: " << islands << "\n";
        cout << "bridges: " << bridges << "\n";
        cout << "buses needed: " << buses << "\n";
        if (mi+1 != maps.size()) cout << "\n";
    }
    return 0;
}
