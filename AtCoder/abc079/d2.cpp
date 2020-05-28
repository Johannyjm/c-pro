#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> cost(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> cost[i][j];

    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    const int INF = 1001001001;
    vector<int> dist2one(10, INF);
    dist2one[1] = 0;

    rep(s, 10){
        if(s == 1) continue;
        vector<int> dist(10, INF);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, s));

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            int v = p.second;
            pq.pop();

            rep(nv, 10){
                if(nv == v) continue;

                if(dist[nv] > dist[v] + cost[v][nv]){
                    dist[nv] = dist[v] + cost[v][nv];

                    pq.push(make_pair(dist[nv], nv));
                }
            }
        }

        dist2one[s] = dist[1];
    }

    int res = 0;
    rep(i, h) rep(j, w){
        if(a[i][j] == -1) continue;
        res += dist2one[a[i][j]];
    }

    cout << res << endl;

    return 0;
}