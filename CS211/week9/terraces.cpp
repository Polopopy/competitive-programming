#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y;                    // X = columns, Y = rows
    if (!(cin >> X >> Y)) return 0;

    vector<vector<int>> h(Y, vector<int>(X));
    for (int r = 0; r < Y; ++r)
        for (int c = 0; c < X; ++c)
            cin >> h[r][c];

    vector<vector<char>> vis(Y, vector<char>(X, 0));
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    long long ans = 0;

    for (int r0 = 0; r0 < Y; ++r0) {
        for (int c0 = 0; c0 < X; ++c0) {
            if (vis[r0][c0]) continue;

            int level = h[r0][c0];
            queue<pair<int,int>> q;
            q.push({r0, c0});
            vis[r0][c0] = 1;

            int compSize = 0;
            bool hasLowerNeighbor = false;

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                ++compSize;

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= Y || nc < 0 || nc >= X) continue;
                    if (h[nr][nc] < level) {
                        hasLowerNeighbor = true;         // escape path
                    } else if (h[nr][nc] == level && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }

            if (!hasLowerNeighbor) ans += compSize;
        }
    }

    cout << ans << "\n";
    return 0;
}
