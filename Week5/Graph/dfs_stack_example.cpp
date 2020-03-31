
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<vector<int> > E ={{0, 0, 0, 0, 0},
                         {2, 0, 0, 0, 0}, // Edge, node:1 -> 2
                         {3, 4, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};
bool vis[5];

int main() {

    stack<tuple<int, int, int>> S;

    for (int i = 0; i < 5;i++) vis[i] = false;

    int root = 1;
    vis[root] = true;
    S.emplace(root, 0, 0);

    while(!S.empty()) {
        auto [u, cur, dep] = S.top(); S.pop(); // cur:=current index
        for (int i = cur; i < E[u].size();i++) {
            int v = E[u][i];
            if (vis[v]) continue;

            vis[v] = true;
            S.emplace(u, i, dep);
            S.emplace(v, 0, dep+1);
            break;
        }

    }


    return 0;
}

