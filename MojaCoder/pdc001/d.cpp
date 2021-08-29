#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> g(n);
    rep(_, n-1){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int res = 0;
    queue<pair<int, ll>> q;
    vector<bool> seen(n, false);
    rep(st, n){
        ll now = a[st];
        seen.assign(n, false);
        seen[st] = true;
        q.push({st, now});
        while(!q.empty()){
            auto [v, G] = q.front();
            q.pop();
            seen[v] = true;

            for(int nv: g[v]){
                if(seen[nv]) continue;
                
                ll ng = gcd(G, a[nv]);
                if(ng == 1) ++res;
                q.push({nv, ng});
            }
        }
    }

    cout << res/2 << endl;

    return 0;
}