#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];

    ll ok = 1ll << 33;
    ll ng = -1;

    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        vector<vector<int>> g(n);
        rep(i, n) rep(j, n){
            ll d = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            if(d <= (__int128_t)p[i]*(__int128_t)mid){
                g[i].push_back(j);
            }
        }

        bool flg = false;
        rep(i, n){
            vector<bool> seen(n, false);
            seen[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(auto nv: g[v]){
                    if(seen[nv]) continue;

                    seen[nv] = true;
                    q.push(nv);
                }
            }

            bool subflg = true;
            rep(i, n){
                if(!seen[i]) subflg = false;
            }

            if(subflg) flg = true;
        }

        if(flg) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;


    return 0;
}