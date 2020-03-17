# https://codeforces.com/problemset/problem/1304/B
# AC

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m, l = 0, max_value = 0, max_index = -1;
pair<int, int> x;
queue<pair<int,int>> id;
string s;

int check_palindrome(string s) {
    int length = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] == s[s.size()-1 - i]) {length++; continue;}
        length = 0;
        break;
    }
    return length * (2 + s.size() % 2);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m;
    string *S = new string[n];

    for (int i = 0; i < n; i++) cin >> S[i];

    /// Case of one element
    if (m == 1) {
        cout << 1 << "\n" << S[0];
        return 0;
    }

    /// Case of more element
    // check self whether is a palindrome
    for (int i = 0; i < n; i++) {
        l = check_palindrome(S[i]);
        if (max_value < l) {
            max_value = l;
            max_index = i;
        }
    }
    s = max_index == -1 ? "\0" : S[max_index];

    //
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            l = check_palindrome(S[i] + S[j]);
            if (l) id.push(pair<int,int>(i, j));
        }

    while (!id.empty()) {
        x = id.front();
        s = S[x.first] + s + S[x.second];
        id.pop();
    }

    cout << s.size() << "\n" << s;
    return 0;
}
