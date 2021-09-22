// dfsを使ってグラフを作成しなおしてから、ダイクストラ法でとくことができる。(9/19に実装する)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define rep(i, n) for (int i = 0; i < n; i++)
const int inf = 5000 * 10000 + 1000;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n), r(n);
  rep(i, n) cin >> c[i] >> r[i];
  vector<vector<int>> o_map(n);
  vector<vector<p>> map(n);
  int a, b;
  rep(i, k) {
    cin >> a >> b;
    a--;
    b--;
    o_map[a].push_back(b);
    o_map[b].push_back(a);
  }
  // 全ての点に対してC[i]回で行くことができる点を調べて新しいグラフを作る(bfs)
  rep(i, n) {
    vector<int> o_dist(n, -1);
    o_dist[i] = 0;
    // point, dist
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int cur = que.front();
      que.pop();
      for (int comp : o_map[cur]) {
        if (o_dist[comp] == -1) {
          o_dist[comp] = o_dist[cur] + 1;
          que.push(comp);
        }
      }
    }
    // 辿り着いた点に対して新しいグラフを作成する
    // 接続されている点 + コスト
    rep(j, n) {
      if (o_dist[j] == -1 || o_dist[j] > r[i]) continue;
      map[i].push_back({j, o_dist[j] * c[i]});
    }
  }
//   rep(i, n) {
//     cout << i << endl;
//     for (p comp : map[i]) {
//       cout << "point: " << comp.first << ", cost: " << comp.second << endl;
//     }
//   }
  // 以下でダイクストラ法を使って最短経路の計算を行う
  vector<int> dist(n, inf);
  priority_queue<p, vector<p>, greater<p>> pque;
  dist[0] = 0;
  pque.push({0, 0});
  while (!pque.empty()) {
    // dist, point id
    p cur = pque.top();
    pque.pop();
    if (cur.first > dist[cur.second]) continue;
    for (p comp : map[cur.second]) {
      int temp_dist = comp.second + dist[cur.second];
      if (temp_dist < dist[comp.first]) {
        dist[comp.first] = temp_dist;
        pque.push({temp_dist, comp.first});
      }
    }
  }
  cout << dist[n - 1] << endl;
}