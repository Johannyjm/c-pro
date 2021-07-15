#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, Q;
    cin >> n >> Q;
    
    vector<vector<int>> g(n);
    rep(_, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> iseven(n, -1);
    iseven[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(iseven[nv] != -1) continue;
            iseven[nv] = 1 - iseven[v];
            q.push(nv);
        }
    }

    rep(_, Q){
        int c, d;
        cin >> c >> d;
        --c;
        --d;

        if(iseven[c] == iseven[d]) puts("Town");
        else puts("Road");
    }

    return 0;
}