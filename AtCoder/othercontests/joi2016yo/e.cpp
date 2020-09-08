#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    ll p, q;
    cin >> p >> q;
    vector<int> c(k);
    rep(i, k) {
        cin >> c[i];
        --c[i];
    }

    vector<vector<int>> g(n);
    rep(_, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> cost(n, p);

    const int INF = 1001001001;
    rep(i, k){
        queue<int> que;
        que.push(c[i]);
        cost[c[i]] = 1LL<<60;
        vector<int> dist(n, INF);
        dist[c[i]] = 0;

        bool flg = false;
        while(!que.empty()){
            int v = que.front();
            que.pop();

            for(int nv: g[v]){
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
                if(dist[nv] <= s) cost[nv] = q;
                else{
                    flg = true;
                    break;
                }

            }
            // rep(j, n) cout << dist[j] << " ";
            // cout << endl;

            if(flg) break;
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 0));
    vector<ll> dist(n, 1LL<<60);
    dist[0] = 0;
    cost[0] = 0;
    cost[n-1] = 0;
    rep(i, k) cost[c[i]] = 1LL<<60;
    while(!pq.empty()){
        pair<ll, int> pa = pq.top();
        pq.pop();
        int v = pa.second;

        for(int nv: g[v]){
            if(dist[v] + cost[nv] < dist[nv]){
                dist[nv] = dist[v] + cost[nv];
                pq.push(make_pair(dist[nv], nv));
            }
        }
    }
    // rep(i, n) cout << i+1 << ": " << cost[i] << " ";
    // cout << endl;
    // rep(i, n) cout << i+1 << ": " << dist[i] << " ";
    // cout << endl;
    cout << dist[n-1] << endl;

    return 0;
}