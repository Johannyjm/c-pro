#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x), b(y), c(z);
    ll sma = 0;
    ll smb = 0;
    ll smc = 0;
    rep(i, x){
        cin >> a[i];
        sma += a[i];
    }
    rep(i, y){
        cin >> b[i];
        smb += b[i];
    }
    rep(i, z){
        cin >> c[i];
        smc += c[i];
    }

    if(min({sma, smb, smc}) != smc){
        if(min({sma, smb, smc}) == sma) swap(a, c);
        else swap(b, c);
    }

    // multiset<ll, greater<ll>> ms;
    vector<ll> ab;
    rep(i, x) rep(j, y){
        // ms.insert(a[i]+b[j]);
        ab.push_back(a[i]+b[j]);
    }

    // for(auto e: ms) cout << e << " ";
    // cout << endl;

    sort(ab.begin(), ab.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());

    vector<ll> res;
    rep(i, min(x+y, k)) rep(j, min(z, k)){
        res.push_back(ab[i]+c[j]);
    }

    sort(res.begin(), res.end(), greater<ll>());

    rep(i, k) cout << res[i] << endl;

    return 0;
}