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

    vector<ll> s(a), t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];

    rep(_, q){
        ll x;
        cin >> x;

        int idx_a = lower_bound(s.begin(), s.end(), x) - s.begin();
        int idx_b = lower_bound(t.begin(), t.end(), x) - t.begin();

        // cout << idx_a << " " << idx_b << endl;

        if(idx_a==a && idx_b==b){
            cout << max(x-s.back(), x-t.back()) << "\n";
            continue;
        }
        if(idx_a==0 && idx_b==0){
            cout << max(s.front()-x, t.front()-x) << "\n";
            continue;
        }
        if(idx_a==a && idx_b==0){
            cout << t.front()-s.back() + min(x-s.back(), t.front()-x) << "\n";
            continue;
        }
        if(idx_a==0 && idx_b==b){
            cout << s.front()-t.back() + min(s.front()-x, x-t.back()) << "\n";
            continue;
        }

        if(idx_a==a){
            ll res = t[idx_b]-x + t[idx_b]-s.back();
            ll cand = x-t[idx_b-1];
            if(t[idx_b-1] > s.back()) cand += t[idx_b-1]-s.back();
            ll cand2 = x-s.back() + t[idx_b]-s.back();
            ll cand3 = x-s.back();
            if(s.back() > t[idx_b-1]) cand += s.back()-t[idx_b-1];
            cand = min({cand, cand2, cand3});
            cout << min(res, cand) << " 5\n";
            continue;
        }
        if(idx_a==0){
            ll res = x-t[idx_b-1] + s.front()-t[idx_b-1];
            ll cand = t[idx_b]-x;
            if(t[idx_b] < s.front()) cand += s.front()-t[idx_b];
            cout << min(res, cand) << "\n";
            continue;
        }
        if(idx_b==b){
            ll res = s[idx_a]-x + s[idx_a]-t.back();
            ll cand = x-s[idx_a-1];
            if(s[idx_a-1] > t.back()) cand += s[idx_a-1]-t.back();
            ll cand2 = x-t.back() + s[idx_a]-t.back();
            ll cand3 = x-t.back();
            if(t.back() > s[idx_a-1]) cand += t.back()-s[idx_a-1];
            cand = min({cand, cand2, cand3});
            cout << min(res, cand) << " 7\n";
            continue;
        }
        if(idx_b==0){
            ll res = x-s[idx_a-1] + t.front()-s[idx_a-1];
            ll cand = s[idx_a]-x;
            if(s[idx_a] < t.front()) cand += t.front()-s[idx_a];
            cout << min(res, cand) << "\n";
            continue;
        }

        ll res1 = s[idx_a]-x;
        if(s[idx_a] < t[idx_b]) res1 += min(t[idx_b]-s[idx_a], s[idx_a]-t[idx_b-1]);

        ll res2 = x-s[idx_a-1];
        if(s[idx_a-1] > t[idx_b-1]) res2 += min(s[idx_a-1]-t[idx_b-1], t[idx_b]-s[idx_a-1]);

        ll res3 = t[idx_b]-x;
        if(t[idx_b] < s[idx_a]) res3 += min(s[idx_a]-t[idx_b], t[idx_b]-s[idx_a-1]);

        ll res4 = x-t[idx_b-1];
        if(t[idx_b-1] > s[idx_a-1]) res4 += min(t[idx_b-1]-s[idx_a-1], s[idx_a]-t[idx_b-1]);

        cout << min({res1, res2, res3, res4}) << " 8\n";
    }

    return 0;
}