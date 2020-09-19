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
    vector<vector<int>> dist_;
    for(int e = 0; e < m; ++e){
        dist_ = cost;
        dist_[a[e]][b[e]] = INF;
        dist_[b[e]][a[e]] = INF;
        
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
                }
            }
        }
        
        bool flg = true;
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){
            if(dist_[i][j] != dist[i][j]){
                flg = false;
                break;
            }
        }

        if(flg) ++res;
    }

    cout << res << endl;

    return 0;
}
