# https://codeforces.com/contest/1107/problem/C
# AC

#include <algorithm>
#include <iostream>
using namespace std;

int i, j, n, k, x, a[200005];
long long total = 0;

string s;

int main() {

    scanf("%d%d", &n, &k);

    for (i=0;i<n;i++) scanf("%d", &x), a[i]=x, total+=x;
    cin >> s;

    for (i = 0; i < s.size(); i = j) {
        for (j = i; s[i] == s[j]; j++);
        sort(a+i, a+j, less<int>());
        for (;0 < j - k and i < j - k;i++) total-=a[i];
    }

    cout << total;

    return 0;
}

