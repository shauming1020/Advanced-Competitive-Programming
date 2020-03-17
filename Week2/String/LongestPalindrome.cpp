# https://codeforces.com/problemset/problem/1304/B
# AC

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m, i, j;
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

    for (i = 0; i < n; i++) cin >> S[i];

    /// Case of one element
    if (m == 1) {
        cout << 1 << "\n" << S[0];
        return 0;
    }

    /// Case of more element
    // check self whether is a palindrome
    for (i = 0; i < n; i++) {
        if (0 < check_palindrome(S[i])) {
            break;
        }
    }
    s = i == n ? "\0" : S[i]; // if i == n, that was there are no palindrome.

    //
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (check_palindrome(S[i] + S[j])) id.push(pair<int,int>(i, j));

    while (!id.empty()) {
        x = id.front();
        s = S[x.first] + s + S[x.second];
        id.pop();
    }

    cout << s.size() << "\n" << s;
    return 0;
}
