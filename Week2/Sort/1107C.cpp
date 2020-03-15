#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, k, x, max_num = 0, del_num = 0; char tmp;
map<int, int> M[26]; // <dmg, index>
vector<int> V; vector<map<int, int>::iterator> C;
 
bool cmp(const map<int, int>::iterator &a, const map<int, int>::iterator &b) {return a->second < b->second;}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
    for (scanf("%d%d", &n, &k);n--;) scanf("%d", &x), V.push_back(x), max_num += x;
    for (n = 0;n < V.size();n++) {
        cin >> tmp; M[int(tmp) - 97].insert(pair<int, int>(n, V[n]) );} // int('a') = 97
 
    for (int i = 0; i < 26; i++) {
        if (M[i].empty()) continue;
        C.clear();
        for (map<int,int>::iterator it = M[i].begin();it != M[i].end(); it++) {
            x = it->first;
            if (!C.empty() && x - C.back()->first > 1) {
                sort(C.begin(), C.end(), cmp);
                for (int j = 0; j < C.size() - k; j++) del_num += C[j]->second;
                C.clear();
            }
            C.push_back(it);
        }
        if (!C.empty() && C.size() != 1 ) {
            sort(C.begin(), C.end(), cmp);
            for (int j = 0; j < C.size() - k; j++) del_num += C[j]->second;
        }
    }
 
    printf("%d", max_num - del_num);
 
    return 0;
}
