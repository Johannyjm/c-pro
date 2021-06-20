#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll weight;
    Edge(int t, ll w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    

    return 0;
}
