#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    vector<ll> cand;
    ll res = 0;
    rep(i, 1<<3){
        cand.clear();
        vector<int> rev(3, 0);
        rep(j, 3){
            if(i & (1<<j)){
                rev[j] = 1;
            }
        }
        
        rep(j, n){
            ll x_ = (rev[0]? x[j]: -x[j]);
            ll y_ = (rev[1]? y[j]: -y[j]);
            ll z_ = (rev[2]? z[j]: -z[j]);

            cand.push_back(x_ + y_ + z_);
        }

        sort(cand.begin(), cand.end(), greater<ll>());

        ll sm = 0;
        rep(j, m){
            sm += cand[j];
        }

        res = max(res, sm);
    }

    cout << res << endl;


    return 0;
}