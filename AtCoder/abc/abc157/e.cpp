#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q, i, c, l, r, cmd;
    string s;
    cin >> n >> s >> q;
    ll kinds[n+1][26] = {0};
    kinds[1][s[0]-'a'] = 1;

    vector<vector<ll>> changed(26, vector<ll>());

    for(int i = 2; i < n+1; ++i){
        rep(j, 26) kinds[i][j] = kinds[i-1][j];
        kinds[i][s[i-1]-'a'] += 1;
    }

    rep(i, q){
        cin >> cmd;

        if(cmd == 1){
            cin >> i >> c;
            changed[s[i-1] - 'a'].push_back(-i);
            changed[c - 'a'].push_back(i);
        }
        else{
            cin >> l >> r;
            ll res = 0;
            rep(j, 26){
                ll num = kinds[r][j] - kinds[l-1][j];
                int idx = 0;
                while(changed[j][idx]){
                    ll value = changed[j][idx];
                    if(l<value && value<=r) {
                        if(value<0) --num;
                        else ++num;
                    }
                    ++idx;
                }
                
                if(num > 0) ++res;
            }
            cout << res << endl;
        }
    }

    return 0;
}