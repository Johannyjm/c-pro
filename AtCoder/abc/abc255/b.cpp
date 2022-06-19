#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_set<int> bright;
    rep(i, k){
        int a_;
        cin >> a_;
        a[i] = a_-1;
        bright.insert(a_-1);
    }


    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll res_sq = 0;
    rep(i, n){
        if(bright.count(i)) continue;

        ll mindist_sq = 1ll << 60;
        for(auto j: bright){
            ll dist_sq = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);

            mindist_sq = min(mindist_sq, dist_sq);
        }

        res_sq = max(res_sq, mindist_sq);
    }

    cout << setprecision(20);
    cout << sqrt(res_sq) << endl;

    return 0;
}