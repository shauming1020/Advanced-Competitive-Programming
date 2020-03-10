# https://codeforces.com/contest/1154/problem/E
# TLE

#include <iostream>     // std::cout
#include <list>			// std::list
using namespace std;

struct node {
	int Skill, ID;
	node(int s, int i) : Skill{ s }, ID{ i } {};
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, tmp;
	list<node> ls;
	
	cin >> n >> k;
	int *ans = new int[n];

	node header(-1, -1);
	ls.push_back(header);

	for (int id = 0; id < n; id++) {
		ans[id] = 0;
		cin >> tmp;
		node t(tmp, id);
		ls.push_back(t);
	}

	int coach = 0;
	while (!ls.empty()) {
		
		coach = coach % 2 == 0 ? 1 : 2;

		list<node>::iterator max = ls.begin();
		for (list<node>::iterator i = ls.begin(); i != ls.end(); i++)
			max = i->Skill > max->Skill ? i : max;

		list<node>::iterator it = max;

		it++;
		for (int i = 0; it != ls.end() && i < k; ++i, ++it) {
			ans[it->ID] = coach;
		}
		
		for (int i = 0; max != ls.begin() && i < k; ++i, --max) {
			ans[max->ID] = coach;
		}
		if (max->ID != -1) ans[max->ID] = coach;

		ls.erase(max, it);
	}


	for (int i = 0; i < n; i++) cout << ans[i];
	
	system("pause");
	return 0;
}
