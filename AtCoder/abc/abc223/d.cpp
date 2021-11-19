#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge {
    int to;
    Edge(int t): to(t) {}
};

using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
            }
        }
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end());

    Graph g(n);
    rep(i, m){
        g[ab[i].first].push_back(Edge(ab[i].second));
    }

    vector<int> res = topo_sort(g);

    for(auto e: res) cout << e+1 << " ";
    cout << endl;
    

    return 0;
}