# https://leetcode.com/problems/minimum-path-sum/
# RT

#include <bits/stdc++.h>
#include <vector>
#define endl '\n'
#define INF 0x3f3f3f3f
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid[0].size()+1, N = grid.size()+1;
        int **dp = new int*[M];
        for (int i = 0; i < M; i++) dp[i] = new int[N];

        /// init
        for (int k = 0; k < max(M,N); k++) dp[0][k] = dp[k][0] = INF;
        dp[0][0] = dp[0][1] = dp[1][0] = 0;

        /// main
        for (int i = 1; i < M; i++)
            for(int j = 1; j < N; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];

        /// return
        return dp[M-1][N-1];

    }
};

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> G = {{1,3,1},{1,5,1},{4,2,1}};

    Solution s;
    cout << s.minPathSum(G);

    return 0;
}


