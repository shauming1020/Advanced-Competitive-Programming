# https://codeforces.com/contest/327/problem/A
# AC

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, a[100], dp[100][100], sum, ans;

int flip(int &x) {
    return 1 - x > 0 ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    sum = 0;
    for (int i = 0; i < N; i++) cin >> a[i], sum+=a[i];

    /// inital dp
    memset(dp, 0, sizeof(dp));
    dp[0][0] = sum + flip(a[0]);
    //cout << dp[0][0] << " ";
    for (int j = 1; j < N; j++) {
        dp[0][j] = dp[0][j-1] + flip(a[j]);
        //cout << dp[0][j] << " ";
    }
    //cout << endl;

    ///
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i == j) dp[i][j] = dp[i-1][j] - flip(a[i-1]);
            else dp[i][j] = dp[i][j-1] + flip(a[j]);
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    ans = dp[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ans = ans < dp[i][j] ? dp[i][j] : ans;
        }
    }

    cout << ans;

    return 0;
}


