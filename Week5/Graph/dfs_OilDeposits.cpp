# https://onlinejudge.org/external/5/572.pdf
# AC

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<char>> graph;
int m, n;

void dfs(int row, int col) {
    if (graph[row][col] == '*') return;
    graph[row][col] = '*';

    for (int drow = -1; drow <= 1; drow++) // -1, 0, 1
        for (int dcol = -1; dcol <= 1; dcol++)
            if (row + drow >= 0 && row + drow < m
            && col + dcol >= 0 && col + dcol < n)
                dfs(row + drow, col + dcol);
}

int main() {
    while (true) {
        cin >> m >> n;
        if (m == 0 or n == 0) break;

        /// init
        graph = vector<vector<char> >(m, vector<char>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];

        /// visit
        int count = 0;
        for (int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if (graph[i][j] == '@')
                    {dfs(i, j); count++;}

        cout << count << endl;
    }

    return 0;
}
