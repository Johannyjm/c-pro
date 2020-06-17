#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(v, n){
        int res = 0;
        vector<bool> seen(n, false);
        seen[v] = true;

        for(int nv: g[v]) seen[nv] = true;

        for(int nv: g[v]){
            for(int nnv: g[nv]){
                if(seen[nnv]) continue;
                seen[nnv] = true;
                ++res;
            }
        }
        cout << res << endl;
    }

    return 0;
}