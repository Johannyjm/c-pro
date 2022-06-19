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
    rep(i, k){
        int a_;
        cin >> a_;
        a[i] = a_ - 1;
    }
    vector<ll> x(n), y(n);
    rep(i, n){
        int x_, y_;
        cin >> x_ >> y_;
        x[i] = x_-1;
        y[i] = y_-1;
    }
    ll ok = 1ll << 60;
    ll ng = 0;

    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        // cout << ok << " " << ng << endl;

        bool flg = true;
        rep(i, n){
            for(auto j: a){
                ll d2 = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                // cout << i << " " << j << " " << d2 << endl;
                if(d2 > mid){
                    flg = false;
                    break;
                }
            }

            if(!flg) break;
        }        

        if(flg) ok = mid;
        else ng = mid;
    }

    cout << setprecision(20);
    cout << sqrt(ok) << endl;

    return 0;
}