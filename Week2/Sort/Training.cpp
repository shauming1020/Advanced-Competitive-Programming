#include <iostream>     // std::cout
#include <algorithm>	// std::sort
#include <vector>		// std::vector
using namespace std;

bool cmp(const int& a, int &b) {
	return a > b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int *Case = new int[T], count = T;


	while (count--) {

		int N, P;
		cin >> N >> P;

		vector<int> *S = new vector<int>(N);
		for (int i = 0; i < N; i++) cin >> S->at(i);

		sort(S->begin(), S->end(), cmp);

		int min = 0x13131313, same, sum;
		for (int i = 0; i < N; i++) {
			int tmp = S->at(i);
			sum = 0; same = 1;
			for (int j = i + 1; j < N; j++) {

				if (tmp == S->at(j)) { same++; i = j; }
				else {
					sum += tmp - S->at(j);
					same++;
				}
				if (same == P) { min = sum < min ? sum : min; break; }
			}
		}

		Case[count] = min;
	}


	for (int i = T; i >= 0; i--) cout << "Case #" << i+1 << ": " << Case[i] << "\n";

	return 0;
}
