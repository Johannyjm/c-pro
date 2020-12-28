#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

// returns (x, y, gcd(a, b)) s.t. ax + by = gcd(a, b)
vector<ll> ext_gcd(ll a, ll b){
    if(a == 0) return {0, 1, b};
    vector<ll> G = ext_gcd(b%a, a);
    ll x = G[0];
    ll y = G[1];
    ll g = G[2];
    
    return {y-b/a*x, x, g};
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll n, s, k;
        cin >> n >> s >> k;

        vector<ll> G = ext_gcd(k, n);

        if(s%G[2] != 0){
            cout << -1 << endl;
            continue;
        }

        if(G[2] != 1){
            n /= G[2];
            s /= G[2];
            k /= G[2];
        }

        ll inv_k = G[0];
        ll res = -s * inv_k % n;

        if(res < 0) res += n;

        cout << res << endl;
    }

    return 0;
}