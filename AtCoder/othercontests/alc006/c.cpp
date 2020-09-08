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
    ll k;
    cin >> s >> k;

    char res = '1';
    int oneidx = 0;
    rep(i, s.length()){
        if(s[i] != '1') {
            res = s[i];
            oneidx = i;
            break;
        }
    }

    if(k<=oneidx) cout << 1 << endl;
    else cout << res << endl;;

    return 0;
}