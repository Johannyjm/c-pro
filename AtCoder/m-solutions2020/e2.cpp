#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];

    const ll INF = 1ll << 60;
    vector<ll> res(n+1, INF);
    vector<int> xs, ys, no;
    for(ll i = 0; i < pow(3, n); ++i){
        xs.clear();
        ys.clear();
        no.clear();
        ll dig = i;
        rep(j, n){
            if(dig % 3 == 0) no.push_back(j);
            if(dig % 3 == 1) xs.push_back(j);
            if(dig % 3 == 2) ys.push_back(j);

            dig /= 3;
        }

        ll cost = 0;
        for(int j: no){
            ll dist = min(abs(x[j]), abs(y[j]));
            for(int k: xs) dist = min(dist, abs(x[k]-x[j]));
            for(int k: ys) dist = min(dist, abs(y[k]-y[j]));

            cost += dist * p[j];
        }

        int cnt = xs.size() + ys.size();
        res[cnt] = min(res[cnt], cost);
    }

    rep(i, n+1) cout << res[i] << endl;

    return 0;
}