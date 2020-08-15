#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i, n){
        cin >> p[i];
        --p[i];
    }
    rep(i, n) cin >> c[i];

    ll res = -(1ll << 60);
    rep(start, n){
        ll score = 0;
        int now = start;
        int nxt;
        int endidx = -1;
        ll rangesm;
        rep(i, k){
            nxt = p[now];
            if(nxt == start){
                score += c[nxt];
                // scores.insert(score);
                res = max(res, score);
                rangesm = score;
                endidx = i;
                break;
            }

            score += c[nxt];
            // scores.insert(score);
            res = max(res, score);
            now = nxt;
        }

        if(endidx != -1){
            ll sm = rangesm;
            ll rest = k - endidx - 1;
            ll mx = sm + sm * max(0ll, (rest / (endidx+1)) - 1);
            ll mod = rest % (endidx+1);
            // scores.insert(mx);
            res = max(res, mx);
            int nows = start;
            int nxts;
            int t = endidx+1;
            if(rest < t) t = 0;
            rep(j, t+mod){
                nxts = p[nows];
                mx += c[nxts];
                // scores.insert(mx);
                res = max(res, mx);
                nows = nxts;
            }
        }

    }

    cout << res << endl;

    return 0;
}