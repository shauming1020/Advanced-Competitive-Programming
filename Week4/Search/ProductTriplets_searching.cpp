# https://code.google.com/codejam/contest/5374486/dashboard#s=p0
# AC
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int T, N;
long long cnt, t, A[7010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];

        // sort
        sort(A, A+N);

        // binary search, O(log(r-l))
        cnt = 0;
        for (int x = 0; x < N-1; x++) {
            for (int y = x+1; y <N; y++) {
                t = A[x] * A[y];
                if (t||!A[y]) // t != 0 or A[y] != 0
                    cnt += upper_bound(A+y+1, A+N, t) - lower_bound(A+y+1, A+N, t);
                else cnt += upper_bound(A+x+1, A+y, 0) - lower_bound(A+x+1, A+y, 0);
            }
        }

        cout << "Case #" << i+1 << ": " << cnt << endl;
    }

    return 0;
}

