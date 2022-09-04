#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, m;
vector<ll> a;
vector<vector<int>> g;
// map<int, ll> cost;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> cost;

bool check(ll m){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> cos = cost;

    while(!cos.empty()){
        auto [val, v] = cos.top();
        cos.pop();

        if(val > m) return false;

        for(auto nv: g[v]){
            cos[nv] -= a[v];
        }
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    a.resize(n);
    g.resize(n);

    rep(i, n) cin >> a[i];
    rep(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(v, n){
        ll sm = 0;
        for(auto nv: g[v]){
            sm += a[nv];
        }
        cost.push({sm, v});
    }

    // for(auto k: cost){
    //     cout << k.first << " " << k.second << endl;
    // }


    ll ok = 1ll << 60;
    ll ng = -1;

    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }

    cout << ok << endl;


    return 0;
}