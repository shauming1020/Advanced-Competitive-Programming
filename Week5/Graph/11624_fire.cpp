# https://onlinejudge.org/external/116/11624.pdf
# AC

#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
using namespace std;

int T, R, C;
string input;
vector<vector<int>> maze;
vector<vector<bool>> vis;

// left, right, down, up
int const dr[] = {0, 0, -1, 1};
int const dc[] = {-1, 1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> T;

    while(T--) {
        cin >> R >> C;
        maze = vector<vector<int> >(R, vector<int>(C));
        vis = vector<vector<bool> >(R, vector<bool>(C));
        queue<tuple<int, int, int>> J, F;
        /// init
        for (int r = 0; r < R; r++) {
            cin >> input;
            for (int c = 0; c < C; c++) {
                if (input[c] == '#') maze[r][c] = 0;
                if (input[c] == '.') maze[r][c] = INF;
                if (input[c] == 'J') J.push({r,c,0}), maze[r][c] = INF, vis[r][c] = true;
                if (input[c] == 'F') F.push({r,c,0}), maze[r][c] = 0;
            }
        }

        /// search the shortest trail of fire
        while(!F.empty()) {
            // fr := fire row, fc := fire col, ft := fire time
            auto [fr, fc, ft] = F.front(); F.pop();

            for (int d = 0; d < 4; d++) {
                int nr = fr + dr[d], nc = fc + dc[d]; // next step, new coordinate
                if (nr == R || nc == C || nr < 0 || nc < 0 // over side
                || maze[nr][nc] != INF || maze[nr][nc] == 0) // cannot visit
                    continue;

                maze[nr][nc] = ft + 1;
                F.push({nr,nc,ft+1});
            }
        }

        /// search the shortest trail of joe
        int escape = -1;
        while (!J.empty()) {
            auto [jr, jc, jt] = J.front(); J.pop();
            // visit the exit
            if ((jr == R-1 || jc == C-1) || (jr == 0 || jc ==0)) {
                escape = jt + 1;
                break;
            }

            for (int d = 0; d < 4; d++) {
                int nr = jr + dr[d], nc = jc + dc[d];

                // already visit or cannot visit the value of ft if jt >= ft.
                if (vis[nr][nc] || jt + 1 >= maze[nr][nc]) continue;

                vis[nr][nc] = true;
                J.push({nr,nc,jt+1});
            }
        }

        /// return
        if (escape > -1) cout << escape << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}



