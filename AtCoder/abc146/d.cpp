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
    map<int, int> edges_cnt;
    vector<pair<int, int>> edges(n-1);

    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);

        ++edges_mp[a];
        ++edges_mp[b];
        ++edges_cnt[a];
        ++edges_cnt[b];

        edges[i] = make_pair(a, b);
    }

    int max_edges = 0;
    for(auto edge: edges_mp){
        max_edges = max(max_edges, edge.second);
    }

    vector<int> res(n-1);
    rep(i, n-1){
        int x = edges[i].first;
        int y = edges[i].second;

        int higher;
        if(edges_mp[x] <= edges_mp[y]) higher = y;
        else higher = x;

        res[i] = edges_cnt[higher];
        --edges_cnt[higher];
    }

    cout << max_edges << endl;
    rep(i, n-1) cout << res[i] << endl;

    return 0;
}