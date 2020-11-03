#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if(m == 0){
        puts("Yes");
        return 0;
    }

    vector<int> l(m), r(m), d(m);
    vector<vector<Edge>> g(n);
    dsu uf(n);
    rep(i, m){
        cin >> l[i] >> r[i] >> d[i];
        --l[i];
        --r[i];

        g[l[i]].push_back(Edge(r[i], d[i]));
        g[r[i]].push_back(Edge(l[i], -d[i]));
        uf.merge(l[i], r[i]);
    }

    set<int> starts;
    rep(i, n){
        starts.insert(uf.leader(i));
    }

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    for(auto start: starts){
        dist.assign(n, INF);
        dist[start] = 0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto ne: g[v]){
                int nv = ne.to;
                if(dist[nv] != INF) continue;
               
                dist[nv] = dist[v] + ne.weight;
                q.push(nv);
            }
        }

        rep(i, m){
            if(dist[l[i]]==INF || dist[r[i]]==INF) continue;

            if(dist[r[i]] - dist[l[i]] != d[i]){
                puts("No");
                return 0;
            }
        }
    }

    puts("Yes");




    return 0;
}