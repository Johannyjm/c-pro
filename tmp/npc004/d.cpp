#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

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
    }

    int res = 0;
    rep(st, n){
        vector<int> seen(n, 0);
        seen[st] = 1;
        queue<int> q;
        q.push(st);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            seen[v] = 1;
            for(int nv: g[v]){
                if(seen[nv]) continue;
                
                q.push(nv);
            }
        }

        for(int e: seen) res += e;
    }

    cout << res << endl;

    return 0;
}