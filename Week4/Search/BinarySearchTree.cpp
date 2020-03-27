# https://neoj.sprout.tw/problem/48/
# AC

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int tmp, i;
vector<int> a, s;

void Traversal(int &root, int L, int R) {
    if (L == R) {--i; return;}

    int l = L, r = R, m;
    while (l != r) {
        m = (l + r) / 2;
        if (s[m] < root)
            l = m + 1;
        else r = m;
    }
    m = l; // important

    Traversal(a[++i], L, m);
    Traversal(a[++i], m + 1, R);
    cout << root << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> tmp) a.push_back(tmp);
    s = a;
    sort(s.begin(), s.end());

    i = 0;
    Traversal(a[i], 0, a.size());

    return 0;
}
