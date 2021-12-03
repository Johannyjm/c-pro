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
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
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

    int n;
    cin >> n;

    ll res = 0;
    vector<vector<Edge>> g(n);

    rep(i, n){
        ll t;
        int k;
        cin >> t >> k;
        res += t;
        
        rep(j, k){
            int a;
            cin >> a;
            --a;
            g[i].push_back(Edge(a));
        }
    }

    vector<int> sg = topo_sort(g);

    // for(auto e: sg) cout << e << " ";
    // cout << endl;

    if((int)sg.size() == n) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}