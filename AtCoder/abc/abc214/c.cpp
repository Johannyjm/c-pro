#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    // ll INF = 1ll << 60;
    vector<ll> res = t;

    res[0] = min(res[0], res[n-1] + s[n-1]);
    rep1(i, n){
        res[i] = min(res[i], res[i-1] + s[i-1]);
    }
    res[0] = min(res[0], res[n-1] + s[n-1]);
    rep1(i, n){
        res[i] = min(res[i], res[i-1] + s[i-1]);
    }

    for(auto e: res) cout << e << "\n";
    

    return 0;
}