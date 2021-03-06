#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while(t--){
        ll n, s, k;
        cin >> n >> s >> k;

        ll g = gcd(k, n);
        n /= g;
        s /= g;
        k /= g;

        ll inv_k = inv_mod(k, n);
        // cout << "inv_k: " << inv_k << endl;
        if(inv_k == 1){
            cout << -1 << endl;
            continue;
        }

        ll res = -s * inv_k % n;
        if(res < 0) res += n;

        cout << res << endl;
    }

    return 0;
}