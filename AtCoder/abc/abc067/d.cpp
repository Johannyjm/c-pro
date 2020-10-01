#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

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

    const int INF = 1001001001;
    vector<int> distf(n, INF);
    distf[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(distf[nv] != INF) continue;

            distf[nv] = distf[v] + 1;
            q.push(nv);
        }
    }

    vector<int> dists(n, INF);
    dists[n-1] = 0;
    q.push(n-1);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(dists[nv] != INF) continue;

            dists[nv] = dists[v] + 1;
            q.push(nv);
        }
    }

    // rep(i, n) cout << distf[i] << " ";
    // cout << endl;
    // rep(i, n) cout << dists[i] << " ";
    // cout << endl;

    int fennec = 0;
    int snuke = 0;
    rep(i, n){
        if(distf[i] <= dists[i]) ++fennec;
        else ++snuke;
    }

    if(fennec == snuke) puts("Snuke");
    else if(fennec > snuke) puts("Fennec");
    else puts("Snuke");
    
    return 0;
}