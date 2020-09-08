#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    map<int, int> edges_mp;
    vector<pair<int, int>> edges(n-1);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        
        ++edges_mp[a];
        ++edges_mp[b];

        edges[i] = make_pair(a, b);

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int max_edges = 0;
    for (auto edge: edges_mp){
        max_edges = max(max_edges, edge.second);
    }

    cout << max_edges << endl;

    vector<set<int>> ng_color(n);
    rep(i, n-1){
        int x, y;
        x = edges[i].first;
        y = edges[i].second;

        int higher = max(edges_mp[x], edges_mp[y]);

        rep1(color, higher+1){
            if(!binary_search(ng_color[x].begin(), ng_color[x].end(), color)){
                if(!binary_search(ng_color[y].begin(), ng_color[y].end(), color)){
                    cout << color << endl;
                    ng_color[x].insert(color);
                    ng_color[y].insert(color);
                    break;
                }
            }
        }
    }

    return 0;
}