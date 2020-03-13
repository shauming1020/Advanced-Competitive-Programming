# https://codeforces.com/contest/1238/problem/B
# 
#include <iostream>
#include <set>

using namespace std;

int main(void) {

    int q;
    scanf("%d", &q);

    int *fires = new int[q];
    for (int i = 0; i < q; i++) fires[i] = 0;

    int n, r, c, tmp, dead, fire;
    for (int i = 0; i < q; i++) {
            dead = 0, fire = 0;

            scanf("%d %d", &n, &r);

            set<int> *S = new set<int>;

            for (int i = 0; i < n; i++) {
                scanf("%d", &tmp);
                S->insert(tmp);
            }

            set<int>::iterator tail;

            while (true) {
                tail = S->end(); tail--;
                if (tail == S->begin()) {
                    if (*tail <= dead) break;
                    else {
                        fire++; break;
                    }
                }

                c = *tail; fire++; dead += r;
                for (;tail!=S->begin();tail--)
                    if (*tail <= dead || *tail == c) tail = S->erase(tail);

            }
        fires[i] = fire;
    }

    for (int i = 0; i < q; i++) printf("%d\n", fires[i]);

    return 0;
}

