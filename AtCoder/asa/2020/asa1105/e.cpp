#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    if(p==2){
        ll res = 0;
        rep(i, n){
            if((s[i]-'0')%2==0) res += ll(i+1);
        }
        cout << res << endl;
        return 0;
    }
    if(p==5){
        ll res = 0;
        rep(i, n){
            if((s[i]-'0')%5==0) res += ll(i+1);
        }
        cout << res << endl;
        return 0;
    }

    vector<ll> mods(n+1);
    mods[0] = 0;
    map<ll, ll> modsmp;
    ++modsmp[0];
    ll inv10 = 1;
    rep1(i, n+1){
        ll d = s[n-i] - '0';
        mods[i] = (mods[i-1] + d*inv10%p) % p;
        ++modsmp[mods[i]];
        inv10 = (inv10 * 10%p) % p;
    }

    ll res = 0;
    for(auto itr = modsmp.begin(); itr != modsmp.end(); ++itr){
        if(itr->second > 1){
            ll num = itr->second;
            res += num * (num-1) / 2;
        }
    }

    cout << res << endl;
    
    return 0;
}