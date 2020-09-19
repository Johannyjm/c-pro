#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1001001001;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> cost(n, vector<int>(n, INF));
    for(int i = 0; i < n; ++i) cost[i][i] = 0;
    vector<int> a(m), b(m), c(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];

        cost[a[i]][b[i]] = c[i];
        cost[b[i]][a[i]] = c[i];
    }

    vector<vector<int>> dist = cost;
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = 0;
    for(int e = 0; e < m; ++e){
        bool flg = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(dist[i][j] == dist[i][a[e]] + c[e] + dist[b[e]][j]) flg = false;
                if(dist[i][j] == dist[i][b[e]] + c[e] + dist[a[e]][j]) flg = false;
            }
        }
        
        if(flg) ++res;

    }

    cout << res << endl;

    return 0;
}
