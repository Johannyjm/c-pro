#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<ll> sma(n+1, 0), smb(m, 0);
    rep1(i, n+1) sma[i] = a[i-1] + sma[i-1];
    smb[0] = b[0];
    rep1(i, m) smb[i] = b[i] + smb[i-1];

    ll res = 0;
    rep(i, n+1){
        ll cnt_a = i;
        ll remain = k-sma[i];
        if(remain < 0) break;

        ll cnt_b = upper_bound(smb.begin(), smb.end(), remain) - smb.begin();
        
        res = max(res, cnt_a+cnt_b);
    }

    cout << res << endl;

    return 0;
}