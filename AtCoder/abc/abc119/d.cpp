#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> s, t;
    
    const ll INF = 1ll<<60;
    s.push_back(-INF);
    rep(i, a){
        ll sa;
        cin >> sa;
        s.push_back(sa);
    }
    s.push_back(INF);

    t.push_back(-INF);
    rep(i, b){
        ll ta;
        cin >> ta;
        t.push_back(ta);
    }
    t.push_back(INF);

    rep(_, q){
        ll x;
        cin >> x;

        int idx_a = lower_bound(s.begin(), s.end(), x) - s.begin();
        int idx_b = lower_bound(t.begin(), t.end(), x) - t.begin();

        ll res = INF;
        for(int i = idx_a-1; i <= idx_a; ++i){
            for(int j = idx_b-1; j <=idx_b; ++j){
                res = min(res, abs(x-s[i])+abs(s[i]-t[j]));
                res = min(res, abs(x-t[j])+abs(t[j]-s[i]));
            }
        }
        
        cout << res << "\n";
    }


    return 0;
}