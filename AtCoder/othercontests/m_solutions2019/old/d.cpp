#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> c(n);
    int res = 0;
    rep(i, n){
        cin >> c[i];
        res += c[i];
    }

    sort(c.begin(), c.end());
    res -= c.back();
    vector<int> d(n, -1);
    int ptr = 0;
    queue<int> q;
    rep(v, n){
        if(g[v].size() == 1){
            q.push(v);
            d[v] = ptr;
            ++ptr;
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(d[nv] != -1) continue;
            d[nv] = ptr;
            ++ptr;
            q.push(nv);
        }
    }

    cout << res << endl;
    rep(i, n-1) cout << c[d[i]] << " ";
    cout << c[d.back()] << endl;


    return 0;
}