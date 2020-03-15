# https://codeforces.com/contest/1238/problem/B
# AC

#include <iostream>
#include <set>
using namespace std;
int main(void) {
    int q, n, r, c, tmp, dead, fire;
    for (scanf("%d", &q); q--;) {
        set<int> S;
        for (scanf("%d %d", &n, &r); n--;)
            scanf("%d", &tmp), S.insert(-tmp);
        dead = 0, fire = 0;
        for (auto index : S) fire += index + r * dead++ < 0;
        printf("%d ", fire);
    }
    return 0;
}

