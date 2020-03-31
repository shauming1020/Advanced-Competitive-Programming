# https://onlinejudge.org/external/8/879.pdf
# 

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int T ,N, a, b, *group;
string pins;

int Find(int v) {
  if (v == group[v]) return v;
  return group[v] = Find(group[v]); // Path Compression
}

void Union(int u, int v)
{ group[Find(u)] = Find(v); }

int main() {
    cin >> T;
    while(T--) {
        /// initial
        cin >> N;
        group = new int[N+1];
        for (int v = 1; v <= N; v++) group[v] = v;

        cin.ignore(); // for getline
        while (getline(cin, pins)) {
          if (pins.empty()) break; // for getline

          stringstream sin(pins);
          while (sin >> a >> b) Union(a, b);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++) if (group[i] == i) cnt++;

        cout << cnt << endl;
    }
    return 0;
}



