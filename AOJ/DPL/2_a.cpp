#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    rep(i, m){
        int s, t, d;
        cin >> s >> t >> d;

        g[s].push_back(Edge(t, d));
    }

    const int INF = 1001001001;
    vector<int> dp(1<<n);
    for(int u = 2; u < n; ++u){
        rep(i, 1<<n){
            vector<int> use(n, 0);
            int use_cnt = 0;
            rep(j, n){
                if(i & (1<<j)){
                    use[j] = 1;
                    ++use_cnt;
                }
            }
            if(use_cnt != u) continue;

            
        }
    }




    return 0;
}