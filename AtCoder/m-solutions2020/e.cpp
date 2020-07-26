#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];

    vector<ll> res(n+1, 1ll<<60);

    rep(i, (1<<n)){
        vector<bool> use(n, false);
        
        int cnt = 0;
        int cnt_a;
        rep(j, n){
            if(i & (1<<j)){
                use[j] = true;
                ++cnt;
            }
        }
        
        ll cost = 1ll << 60;
        rep(ii, pow(3, cnt)){
            vector<int> use_a(cnt, 0);
            int buf = ii;
            rep(jj, cnt){
                use_a[jj] = buf % 3;
                buf /= 3;
            }

            cnt_a = 0;
            rep(jj, cnt) cnt_a += use_a[jj];

            if(cnt_a > n) continue;

            ll cost_a = 0;
            rep(jj, n){
                ll dist = 1ll<<60;
                
                dist = min({dist, abs(x[jj]), abs(y[jj])});
                rep(kk, n){
                    if(use[kk] && (use_a[kk] == 0 || use_a[kk] == 2)) dist = min(dist, abs(x[jj] - x[kk]));
                    if(use[kk] && (use_a[kk] == 1 || use_a[kk] == 2)) dist = min(dist, abs(y[jj] - y[kk]));
                }

                cost_a += dist*p[jj];
            }

            cost = min(cost, cost_a);
        }
        if(cost == 0) break;

        res[cnt_a] = min(res[cnt], cost);
    }

    rep(i, n+1){
        cout << res[i] << endl;
    }


    return 0;
}