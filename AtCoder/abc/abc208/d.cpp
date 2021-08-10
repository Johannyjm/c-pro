#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    const ll INF = 1001001001;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    
    for(int i = 0; i < n; ++i) dist[i][i] = 0;
    for(int i = 0; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = c;
    }

    ll res = 0;
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                
                if(dist[i][j] != INF) res += dist[i][j];
            }
        }
    }

    cout << res << endl;

    return 0;
}
