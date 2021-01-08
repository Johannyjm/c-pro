#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

vector<mint> fact, ifact, double_fact;
void init(int n) {
    fact.resize(n+1);
    ifact.resize(n+1);
    double_fact.resize(n+1);
    fact[0] = 1;

    for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;

    ifact[n] = fact[n].inv();
    for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i] * i;

    double_fact[1] = 1;
    for(int i = 3; i <= n; i += 2) double_fact[i] = double_fact[i-2] * i;
}

mint comb(int n, int k){
    return fact[n] * ifact[k] * ifact[n-k];
}
mint perm(int n, int k){
    return fact[n] * ifact[n-k];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    init(220000);

    vector<vector<int>> g(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    mint res = k;
    if(n != 1) res *= perm(k-1, g[0].size());
    queue<int> q;
    q.push(0);
    vector<bool> seen(n, false);
    seen[0] = true;
    
    while(!q.empty()){
        int v = q.front();
        // cout << res.val() << " ";
        q.pop();
        seen[v] = true;

        for(auto nv: g[v]){
            if(seen[nv]) continue;
            if(g[nv].size()-1 > k-2){
                cout << 0 << endl;
                return 0;
            }
            res *= perm(k-2, g[nv].size()-1);
            
            q.push(nv);
        }
    }

    cout << res.val() << endl;

    return 0;
}