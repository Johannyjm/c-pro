#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    ll k;
    cin >> s >> k;

    char res = '1';
    int one_idx = 0;
    rep(i, s.length()){
        if(s[i] != '1') {
            res = s[i];
            one_idx = i;
            break;
        }
    }

    if(k<=one_idx) cout << 1 << endl;
    else cout << res << endl;

}