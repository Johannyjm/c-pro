#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    vector<int> l(n);
    vector<vector<ll>> a(n);
    rep(i, n){
        cin >> l[i];
        vector<ll> a_(l[i]);
        rep(j, l[i]) cin >> a_[j];

        a[i] = a_;
    }

    unordered_map<ll, ll> dp;
    rep(i, l[0]){
        ++dp[a[0][i]];
    }

    rep1(i, n){
        unordered_map<ll, ll> nxt;
        rep(j, l[i]){
            for(auto k: dp){
                ll c = k.first;
                ll d = a[i][j];
                if(c >= LLONG_MAX / d) continue;
                if(c * d > 1000000000000000000) continue;

                nxt[c*d] += k.second;
            }
        }

        dp = nxt;
    }

    cout << dp[x] << endl;

    return 0;
}