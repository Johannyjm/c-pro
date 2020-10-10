#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mod_sub(ll a, ll b){
    return ((a + MOD) - b) % MOD;
}
 
ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll mod_pow(ll x, ll r){
    if (r == 0) return 1;

    else if (r == 1) return x % MOD;

    else if (r % 2 == 0){
        ll t = mod_pow(x, r/2) % MOD;
        return mod_mul(t, t);
    }

    else{
        ll t = mod_pow(x, r/2) % MOD;
        ll k = mod_mul(t, t);
        return ((k % MOD) * (x % MOD)) % MOD;
    }
}
ll mod_div(ll a, ll b){
    return mod_mul(a, mod_pow(b, MOD - 2));
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    ll bit = 0;
    rep(i, h) rep(j, w){
        if(s[i][j] == '.') ++bit;
    }

    const ll INF = 1001001001;
    vector<vector<ll>> cnt(h, vector<ll>(w, -INF));
    vector<vector<ll>> total(h, vector<ll>(w, 0));
        
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        cnt[i][j] = 1;
    }

    vector<vector<ll>> cnt1 = cnt;
    // l to r
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        if(j+1 < w && s[i][j+1] != '#') cnt1[i][j+1] += cnt1[i][j];
    }


    vector<vector<ll>> cnt2 = cnt;
    // r to l
    for(int i = 0; i < h; ++i) for(int j = w-1; j >= 0; --j){
        if(s[i][j] == '#') continue;
        if(j-1>=0 && s[i][j-1]) cnt2[i][j-1] += cnt2[i][j];
    }

    vector<vector<ll>> cnt3 = cnt;
    // u to d
    for(int j = 0; j < w; ++j) for(int i = 0; i < h; ++i){
        if(s[i][j] == '#') continue;
        if(i+1 < h && s[i+1][j] != '#') cnt3[i+1][j] += cnt3[i][j];
    }

    vector<vector<ll>> cnt4 = cnt;
    // d to u
    for(int j = 0; j < w; ++j) for(int i = h-1; i >= 0; --i){
        if(s[i][j] == '#') continue;
        if(i-1>=0 && s[i-1][j] != '#') cnt4[i-1][j] += cnt4[i][j];
    }

    rep(i, h) rep(j, w){
        total[i][j] = cnt1[i][j];
        if(cnt2[i][j]!=1) total[i][j] += cnt2[i][j]-1;
        if(cnt3[i][j]!=1) total[i][j] += cnt3[i][j]-1;
        if(cnt4[i][j]!=1) total[i][j] += cnt4[i][j]-1;
        
    }

    // rep(i, h){
    //     rep(j, w) cout << total[i][j] << " ";
    //     cout << endl;
    // }


    vector<ll> scores(bit+10, 0);


    ll n = mod_pow(2, bit);
    scores[1] = mod_div(n, 2);
    ll base = 2;
    for(ll i = 2; i < bit+1; ++i){
        base = mod_mul(base, 2);
        scores[i] = mod_add(scores[i-1], mod_div(n, base));
    }


    // rep(i, scores.size()) cout << scores[i] << " ";
    // cout << endl;

    ll res = 0;
    rep(i, h) rep(j, w){
        if(total[i][j] < 0) continue;
        res = mod_add(res, scores[total[i][j]]);
    }

    cout << res << endl;

    return 0;
}