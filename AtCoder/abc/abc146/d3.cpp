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

    vector<unordered_set<int>> ng_color(n);
    int max_edges = -1;
    vector<int> res(n-1);
    rep(i, n-1){
        int x, y;
        x = edges[i].first;
        y = edges[i].second;

        int color = max(1, (int)max(ng_color[x].size(), ng_color[y].size()));
        while(1){
            if(!ng_color[x].count(color)){
                if(!ng_color[y].count(color)){
                    res[i] = color;
                    ng_color[x].insert(color);
                    ng_color[y].insert(color);

                    max_edges = max(max_edges, color);
                    break;
                }
            }
            ++color;
        }
    }

    cout << max_edges << endl;
    rep(i, n-1) cout << res[i] << endl;

    return 0;
}