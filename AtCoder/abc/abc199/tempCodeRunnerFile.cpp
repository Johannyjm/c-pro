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
    vector<vector<ll>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> cnt(n, -1);
    rep(st, n){
        if(cnt[st] != -1) continue;
        
        cnt[st] = 3;
        queue<ll> q;
        q.push(st);
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(cnt[nv] != -1) continue;
                int c = 0;
                for(auto nnv: g[nv]){
                    if(cnt[nnv] != -1) ++c;
                }
                cnt[nv] = max(0, 3 - c);
                q.push(nv);
            }
        }
    }

    ll res = 1;
    rep(i, n) res *= cnt[i];

    cout << res << endl;


    return 0;
}