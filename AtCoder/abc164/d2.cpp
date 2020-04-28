#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<ll> mods(n+1);
    mods[0] = 0;
    map<ll, ll> modsmp;
    ++modsmp[0];
    ll inv10 = 1;
    rep1(i, n+1){
        ll d = s[n-i] - '0';
        mods[i] = (mods[i-1] + d*inv10%2019) % 2019;
        ++modsmp[mods[i]];
        inv10 = (inv10 * 10%2019) % 2019;
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