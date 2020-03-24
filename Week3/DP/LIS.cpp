#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, a[100000], length[100000], pref[100000];

void trace(int i) {
    if (pref[i] != -1) trace(pref[i]);
    cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int n = 0; n < N; n++) {
        /// inital
        length[n] = 1, pref[n] = -1; //

        /// main
        for (int i = 0; i < n; i++)
            if (a[i] < a[n] && length[n] < length[i] + 1){
                length[n] = length[i] + 1;
                pref[n] = i;
            }
    }

    /// return
    int max_length = 0, max_length_pos = 0;
    for (int i = 0; i < N; i++)
        if (max_length < length[i]) {
            max_length = length[i];
            max_length_pos = i;
        }
    cout << "LIS is ";
    trace(max_length_pos);
    cout << endl;
    cout << "and length is " << max_length;

    return 0;
}


