# https://codeforces.com/contest/1287/problem/A
# Accepted

#include <iostream>     // std::cout
#include <string>		
using namespace std;

int main() {

	int t, k, minute;
	char tmp;
	bool change;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	int *output = new int[t];

	for (int g = 0; g < t; g++) {
		cin >> k;

		string state;
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			state += tmp;
		}

		minute = 0; change = true;
		while (change) {
			change = false;
			minute += 1;

			for (int i = 0; i < k - 1; i++) {
				if (state[i] == 'A' && state[i + 1] != 'A') {
					state[i + 1] = 'B';
					change = true;
				}
			}
			for (int i = 0; i < k; i++) {
				if (state[i] == 'B') state[i] = 'A';
			}
		}

		output[g] = minute - 1;
	}

	for (int g = 0; g < t; g++) cout << output[g] << "\n";
	
	return 0;
}
