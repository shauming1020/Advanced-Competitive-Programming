# https://codeforces.com/contest/1238/problem/B
# 

#include <iostream>
#include <set>
using namespace std;

int main(void) {

    int q;
    cin >> q;
    int *fires = new int[q];
    for (int i = 0; i < q; i++) fires[i] = 0;

    for (int i = 0; i < q; i++) {
        int n, r, c, tmp, dead = 0, fire = 0;
            cin >> n >> r;

            set<int> S;

            for (int i = 0; i < n; i++) {
                cin >> tmp;
                S.insert(tmp);
            }

            set<int>::iterator tail = S.end(); tail--;

            while (!S.empty()) {
                if (tail == S.begin()) break;

                c = *tail;
                dead += r;

                for (;tail!=S.begin();tail--)
                    if (*tail <= dead || *tail == c) S.erase(tail);

                tail = S.end(); tail--;

                fire++;
            }
        fires[i] = fire;
    }

    for (int i = 0; i < q; i++) cout << fires[i] << "\n";

    system("pause");
    return 0;
}