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
    vector<priority_queue<int, vector<int>, greater<int>>> g(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push(b);
        g[b].push(a);
    }

    vector<bool> seen(n, false);
    seen[0] = true;

    queue<int> q;
    q.push(0);

    vector<int> prev(n, -1);

    vector<int> res;
    res.push_back(1);
    // int cnt = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        int nv = -1;
        while(!g[v].empty()){
            nv = g[v].top();
            if(seen[nv]) g[v].pop();
            else{
                g[v].pop();
                break;
            }
        }

        if(nv != -1){
            q.push(nv);
            res.push_back(nv+1);
            if(prev[nv] == -1) prev[nv] = v;
            seen[nv] = true;
            // cout << "valid? " << v << " " << nv << " " << prev[v] << endl;
        }

        else{
            if(v != 0){
                // cout << "prev? " << v << " " << nv << " " << prev[v] << endl;
                q.push(prev[v]);
                res.push_back(prev[v]+1);
            }
        }
        // cout << v << " " << nv << " " << prev[v] << endl;
        // cnt++;
        // if(cnt == 5) break;
    }
    // for(auto e: seen) cout << e << " ";
    // cout << endl;
    // for(auto e: prev) cout << e << " ";
    // cout << endl;
    for(auto e: res) cout << e << " ";
    cout << endl;

    return 0;
}