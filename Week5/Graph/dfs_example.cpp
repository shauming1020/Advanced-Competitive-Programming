
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int E[5][5]={{0, 0, 0, 0, 0},
             {2, 0, 0, 0, 0}, // Edge, node:1 -> 2
             {3, 4, 0, 0, 0},
             {0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0}};
bool vis[5];

void dfs(int u, int dep) {
    for(int v : E[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v, dep + 1);
    }
}

int main() {

    for (int i = 0; i < 5;i++) vis[i] = false;

    int root = 1;
    vis[root] = true;
    dfs(root, 0);

    return 0;
}
