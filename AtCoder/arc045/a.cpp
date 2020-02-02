#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string res = "";
    rep(i, s.size()){
        cout << s[i] << endl;
        if(s[i]=='L') res += "< ";
        if(s[i]=='R') res += "> ";
        if(s[i]=='A') res += "A ";
    }

    cout << res.size() << endl;

    rep(i, res.size()-1) cout << res[i];
    cout << endl;

    return 0;
}