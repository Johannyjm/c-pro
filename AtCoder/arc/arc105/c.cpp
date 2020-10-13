#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> w, l, v;
bool check(ll len){
    // vector<ll> w_ = w;
    // sort(w_.begin(), w_.end());

    // do{

    // } while(next_permutation(w_.begin(), w_.end())
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    w.resize(n);
    ll mx_w = 0;
    rep(i, n){
        cin >> w[i];
        mx_w = max(mx_w, w[i]);
    }

    sort(w.begin(), w.end(), greater<ll>());
    vector<ll> ww;
    ww.push_back(w.front());
    rep1(i, n-1){
        if(ww.back() == mx_w){
            ww.push_back(w[i]);
        }
        else{
            if(ww.back() + w[i] <= mx_w) ww.back() += w[i];
            else ww.push_back(w[i]);
        }
    }





    l.resize(m);
    v.resize(m);
    ll mx_l = 0;
    rep(i, m){
        cin >> l[i] >> v[i];

        mx_l = max(mx_l, l[i]);

        if(v[i] < mx_w){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ok = mx_l * n;
    ll ng = -1;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    for(auto e: ww) cout << e << " ";
    cout << endl;

    cout << ok << endl;

    return 0;
}