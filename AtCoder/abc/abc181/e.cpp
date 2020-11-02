#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> h(n), w(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];

    if(n==1){
        ll res = 1ll<<60;
        rep(i, m) res = min(res, abs(h[0]-w[i]));
        cout << res << endl;
        return 0;
    }
    
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    vector<ll> dif(n-1);
    ll difsm = 0;
    rep(i, n-1){
        dif[i] = abs(h[i+1] - h[i]);
        difsm += dif[i];
    }

    vector<ll> dseven, dsodd;
    dsodd.push_back(0);
    dsodd.push_back(dif[0]);
    dseven.push_back(0);
    dseven.push_back(dif[1]);
    for(int i = 2; i < n-1; ++i){
        if(i%2==0) dsodd.push_back(dsodd.back()+dif[i]);
        else dseven.push_back(dseven.back()+dif[i]);
    }

    // for(auto e: dsodd) cout << e << " ";
    // cout << endl;
    // for(auto e: dseven) cout << e << " ";
    // cout << endl;

    ll res = 1ll<<60;
    rep(i, m){
        ll v = w[i];

        int idx = upper_bound(h.begin(), h.end(), v) - h.begin();
        // cout << idx << endl;

        // ll sm = difsm-dif[min((int)n-2, idx-1)];
        // sm += abs(w[i] - h[idx-1]);
        int idx_p = max(0, (idx-1)/2);
        idx_p = min(idx_p, ((int)n+1)/2-1);
        ll sm;
        if(idx%2!=0){
            if(idx==n) sm = dsodd.back() + abs(w[i]-h[idx-1]);
            else sm = dsodd[idx_p] + dseven.back()-dseven[idx_p] + abs(w[i]-h[idx-1]);
        }
        else{
            if(idx==0) sm = dseven.back() + abs(w[i]-h[idx]);
            else{
                idx_p = idx/2;
                sm = dsodd[idx_p] + dseven.back()-dseven[idx_p] + abs(w[i]-h[idx]);
            }
        }

        // cout << idx_p << " " << sm << endl;
        // cout << endl;
        res = min(res, sm);
    }

    cout << res << endl;



    return 0;
}