#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct UnionFind{
    vector<int> p;
    vector<int> r;

    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
    }

    int find(int x){
        if(p[x] == -1) return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++r[y];

        p[x] = y;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, pair<int,  int>>> dist;
    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    rep(_, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        dist.push_back(make_pair(c, make_pair(a, b)));
        cost[a][b] = c;
        cost[b][a] = c;
    }

    sort(dist.begin(), dist.end());

    vector<vector<int>> g(n);
    UnionFind uf(n);
    for(auto edge: dist){
        int cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;;

        if(uf.find(from) != uf.find(to)){
            g[from].push_back(to);
            g[to].push_back(from);

            uf.unite(from, to);
        }
    }

    vector<pair<int, int>> cost_sm(n);
    rep(i, n){
        pair<int, int> c_p = make_pair(0, i);
        rep(j, g[i].size()){
            c_p.first += cost[i][g[i][j]];
        }
        cost_sm[i] = c_p;
    }

    sort(cost_sm.begin(), cost_sm.end(), greater<pair<int, int>>());

    vector<int> goal;
    vector<int> dist2goal(n, INF);
    rep(i, k){
        int v = cost_sm[i].second;
        goal.push_back(v);
        dist2goal[v] = 0;
        for(auto nv: g[v]){
            if(dist2goal[nv] != INF) continue;
            dist2goal[nv] = cost[v][nv];
        }
    }

    // rep(i, goal.size()) cout << goal[i] << " ";
    // cout << endl;

    rep(s, n){
        if(dist2goal[s] != INF) continue;

        vector<int> d(n, INF);
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, s));

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int v = p.second;

            for(auto nv: g[v]){
                if(d[nv] > d[v] + cost[v][nv]){
                    d[nv] = d[v] + cost[v][nv];
                    pq.push(make_pair(d[nv], nv));
                }
            }
        }

        int sm = INF;
        rep(i, k){
            sm = min(sm, d[goal[i]]);
        }
        dist2goal[s] = sm;
    }


    int res = 0;
    rep(i, n){
        res += dist2goal[i];
    }

    cout << res << endl;



    return 0;
}