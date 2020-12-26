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
    s.push_back(-(1ll<<60));
    rep(i, a){
        ll sa;
        cin >> sa;
        s.push_back(sa);
    }
    s.push_back(1ll<<60);

    t.push_back(-(1ll<<60));
    rep(i, b){
        ll tb;
        cin >> tb;
        t.push_back(tb);
    }
    t.push_back(1ll<<60);

    rep(_, q){
        ll x;
        cin >> x;

        int idx_a = lower_bound(s.begin(), s.end(), x) - s.begin();
        int idx_b = lower_bound(t.begin(), t.end(), x) - t.begin();

        ll res = 1ll<<60;
        for(int i = idx_a-1; i <= idx_a; ++i){
            for(int j = idx_b-1; j <= idx_b; ++j){
                ll cand1 = abs(x-s[i]) + abs(s[i]-t[j]);
                ll cand2 = abs(x-t[j]) + abs(t[j]-s[i]);

                res = min({res, cand1, cand2});
            }
        }

        cout << res << endl;
    }

    return 0;
}