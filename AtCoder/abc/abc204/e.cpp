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
    ll l = 0;
    ll r = 1ll<<60;
    while(r - l > 500){
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        if(now+m1+c+(d/(now+1+m1)) < now+m2+c+(d/(now+1+m2))) r = m2;
        else l = m1;
        // cout << l << " " << r << endl;
    }

    ll ret = -1;
    ll mn = 1ll<<60;
    for(int w = l; w <= r; ++w){
        if(now+w+c+(d/(now+1+w)) < mn){
            mn = now+w+c+(d/(now+1+w));
            ret = w;
        }
    }

    return ret;
    // ll x = now+l+c+(d/(now+1+l));
    // ll y = now+r+c+(d/(now+1+r));
    // ll z = now+(l+r)/2+c+(d/(now+1+(l+r)/2));
    // if(min({x, y, z}) == x) return l;
    // if(min({x, y, z}) == y) return r;
    // if(min({x, y, z}) == z) return (l+r) / 2;

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
    // rep(i, n){
    //     g[i].push_back(Edge(i, 1, 0));
    // }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    const ll INF = 1ll<<60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    while(!pq.empty()){
        pair<ll, int> p = pq.top();
        pq.pop();
        ll d = p.first;
        int v = p.second;
        // cout << v << " " << d << endl;

        if(dist[v] != d) continue;

        for(auto ne: g[v]){
            ll wait = findmin(dist[v], ne.c, ne.d);
            ll cost = wait + ne.c + (ne.d / (dist[v] + 1 + wait));
            // cout << v << " " << ne.to << " " << wait << " " << cost << endl;
            if(dist[ne.to] > dist[v] + cost){
                dist[ne.to] = dist[v] + cost;
                pq.push({dist[ne.to], ne.to});
            }
        }
    }

    if(dist[n-1] == INF) cout << -1 << endl;
    else cout << dist[n-1] << endl;

    return 0;
}