#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool all9 = true;
    rep1(i, s.size()){
        if(s[i] == '9') all9 = all9 && true;
        else all9 = false;
    }

    int res = s[0] - '0' - 1 + 9 * (s.size() - 1);
    
    if(all9) cout << res + 1 << endl;
    else cout << res << endl;

    return 0;
}