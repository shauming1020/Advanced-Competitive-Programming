# https://code.google.com/codejam/contest/dashboard?c=5374486
# AC

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int T, N;
long long cnt, A[7010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];

        //
        cnt = 0;
        for (int x = 0; x < N - 2; x++)
            for (int y = x + 1; y < N - 1; y++)
                for (int z = y + 1; z < N; z++)
                    if (A[x] == A[y] * A[z] or
                        A[y] == A[x] * A[z] or
                        A[z] == A[x] * A[y]) cnt++;


        cout << "Case #" << i+1 << ": " << cnt << endl;
    }

    return 0;
}

