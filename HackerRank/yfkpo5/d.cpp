#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge{
    int to;
    char label;

    Edge(int t, char l): to(t), label(l) {}
};

bool ns_is_shorter(string next_s, string other){

    if(other == "INF") return true;
    if(next_s.size() < other.size()) return true;
    if(next_s.size() > other.size()) return false;

    return next_s < other;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const int n_max = 50000; //8192;

    vector<vector<Edge>> g(n_max);

    queue<int> q;
    q.push(1);
    vector<bool> seen(n_max, false);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(seen[v]) continue;

        seen[v] = true;

        int nv;
        
        // A
        nv = v * 2;
        if(nv < n_max){
            g[v].push_back(Edge(nv, 'A'));
            q.push(nv);
        }

        // B
        if(v % 2 == 0){
            nv = v / 2;
            g[v].push_back(Edge(nv, 'B'));
            q.push(nv);
        }

        // C
        if(v > 22){
            nv = v % 22;
            g[v].push_back(Edge(nv, 'C'));
            q.push(nv);
        }
    }

    // rep1(v, 25){
    //     cout << v << endl;
    //     for(auto ne: g[v]) cout << ne.to << ":" << ne.label << ", ";
    //     cout << endl;
    //     cout << endl;
    // }

    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
    pq.push({"", 1});

    vector<string> dist(n_max, "INF");
    dist[1] = "";

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        //if(dist[v] != d) continue;

        for(auto ne: g[v]){
            int nv = ne.to;
            
            string ns = dist[v] + ne.label;

            if(ns_is_shorter(ns, dist[nv])){
                dist[nv] = ns;
                pq.push({dist[nv], nv});
            }
        }
    }

    // rep1(v, 25){
    //     cout << v << ": " << dist[v] << endl;
    // }

    int n;
    cin >> n;
    string res = dist[n];

    if(res == "INF") cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}