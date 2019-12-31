#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string res;
    if('a' <= s[0] && s[0] <= 'z') res = s[0] - 'a' + 'A';
    else res = s[0];

    for(int i = 1; i < s.length(); ++i){
        if('a' <= s[i] && s[i] <= 'z') res += s[i];
        else res += s[i] - 'A' + 'a';
    }

    cout << res << endl;
}