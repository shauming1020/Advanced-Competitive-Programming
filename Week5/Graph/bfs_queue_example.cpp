#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> E = {{0, 0, 0, 0, 0},
                         {2, 4, 0, 0, 0}, // Edge, node:1 -> 2
                         {1, 3, 0, 0, 0},
                         {2, 4, 0, 0, 0},
                         {1, 3, 0, 0, 0}};
bool vis[5];
queue<int> Q;

int main() {

    for (int i = 0; i < 5; i++) vis[0] = false;
    int root = 1;
    Q.push(root); //root
    vis[root] = true;

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        cout << u << endl;
        for (auto &v : E[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            Q.push(v);
        }
    }

    return 0;
}
