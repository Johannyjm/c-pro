#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll c;
    ll d;
    Edge(int to, ll c, ll d): to(to), c(c), d(d) {}
};

ll findmin(ll now, ll c, ll d){
    ll l = max(0.0, pow(d, 0.5) - 5);
    ll r = l + 10;

    ll ret = -1;
    ll mn = 1ll<<60;
    for(ll w = l; w <= r; ++w){
        if(now + w + c + d / (now + 1 + w) < mn){
            mn = now + w + c + d / (now + 1 + w);
            ret = w;
        }
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    rep(i, m){
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        g[a].push_back(Edge(b, c, d));
        g[b].push_back(Edge(a, c, d));
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    const ll INF = 1ll<<60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist[v] != d) continue;
        
        for(auto ne: g[v]){
            ll wait = findmin(dist[v], ne.c, ne.d);
            ll cost = dist[v] + wait + ne.c + (ne.d / (dist[v] + 1 + wait));
            if(dist[ne.to] > cost){
                dist[ne.to] = cost;
                pq.push({cost, ne.to});
            }
        }
    }

    ll res = dist[n-1];
    if(res == INF) res = -1;

    cout << res << endl;


    return 0;
}