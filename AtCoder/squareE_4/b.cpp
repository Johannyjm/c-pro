#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = 1LL << 60;
    rep(i, 1<<n){

        if(i%2==0) continue;

        vector<int> use_idx(n, 0);
        int use_cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                use_idx[j] = 1;
                ++use_cnt;
            }
        }
        if(use_cnt != k) continue;

        ll sum = 0;
        ll mx = a[0];
        rep1(j, n){
            if(use_idx[j]){
                
                if(mx >= a[j]) {
                    sum += mx+1 - a[j];
                    ++mx;
                }
            }

            if(mx < a[j]) mx = a[j];
        }

        res = min(res, sum);
    }

    cout << res << endl;

    return 0;
}