# https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/00000000000698d6
# AC

#include <iostream>     // std::cout
#include <algorithm>	// std::sort
#define INF 0x3f3f3f3f

using namespace std;
typedef long long LL;
const int MAXN = 1e5 +10;

LL T, N, P, S[MAXN], t, i, j, k, x, sum, min_sum;

int main() {

    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d%d", &N, &P);
        for (i = 0;i < N; i++) scanf("%d", &S[i]);

        sort(S, S + N, greater<int>());

        min_sum = INF;
        for (i = 0; i < N - P + 1; i+=k) {
            sum = 0; k = 0;
            for (j = i; j < i + P and i + P <= N;j++) {
                x = S[i] - S[j];
                if (x == 0) { k++; continue;}
                sum += x;
            }
            min_sum = sum < min_sum ? sum : min_sum;
            if (min_sum == 0) break;
        }

        cout << "Case #" << t + 1 << ": " << min_sum << "\n";
    }

	return 0;
}
