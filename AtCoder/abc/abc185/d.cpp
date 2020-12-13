#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i, m){
        cin >> a[i];
        --a[i];
    }
    
    a.push_back(-1);
    a.push_back(n);
    sort(a.begin(), a.end());


    ll mn_range = 1001001001;
    vector<ll> ranges;
    rep(i, m+1){
        ll range = a[i+1] - a[i] -/*  */ 1;

        if(range == 0) continue;

        ranges.push_back(range);

        mn_range = min(mn_range, range);
    }

    if(mn_range == 1001001001){
        cout << 0 << endl;
        return 0;
    }

    // cout << mn_range << endl;

    ll res = 0;
    for(auto e: ranges) res += (e + mn_range - 1) / mn_range;

    cout << res << endl;


    return 0;
}