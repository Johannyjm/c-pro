#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    string s;
    string res = "";
    while(cin >> s){
        if(s[0]=='L') res += "< ";
        if(s[0]=='R') res += "> ";
        if(s[0]=='A') res += "A ";
    }

    rep(i, res.size()-1) cout << res[i];
    cout << endl;

    return 0;
}