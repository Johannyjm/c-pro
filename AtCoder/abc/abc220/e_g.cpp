#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    int m = pow(2, n);
    cout << m << endl;
    vector<vector<int>> g(m);
    rep1(i, pow(2, n-1)){
        cout << i << " " << i * 2 << " " <<  i * 2 + 1 << endl;
        g[i].push_back(i*2);
        g[i].push_back(i*2+1);
        g[i*2].push_back(i);
        g[i*2+1].push_back(i);
    }
    cout << 0<< endl;
    int res = 0;
    rep1(st, m){
        queue<int> q;
        q.push(st);
        int INF = 1001001001;
        vector<int> dist(m, INF);
        dist[st] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto nv: g[v]){
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }

        rep1(i, m){
            // cout << dist[i] << " ";
            if(dist[i] == d) ++res;
        }
        // cout << endl;
    }

    cout << res << endl;

    return 0;
}