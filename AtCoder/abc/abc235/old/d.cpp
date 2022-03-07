#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int rotate(int n){
    int tmp = n;
    int d = 0;
    while(tmp){
        ++d;
        tmp /= 10;
    }
    int m = 1;
    rep(_, d-1) m *= 10;

    int top = n / m;
    int ret = n % m;
    ret *= 10;
    return ret + top;

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, n;
    cin >> a >> n;

    vector<unordered_set<int>> g(11000000);
    queue<int> q;
    q.push(n);

    const int INF = 1001001001;
    vector<int> dist(11000000, INF);
    dist[n] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        // 1
        if(v % a == 0){
            int nv = v / a;
            if(g[v].count(nv) == 0){
                g[v].insert(nv);

                dist[nv] = dist[v] + 1;

                q.push(nv);
            }
        }
        
        // 2
        if(v > 10){ // && v % 10 != 0){
            int nv = rotate(v);
            if(g[v].count(nv) == 0){
                g[v].insert(nv);
                
                dist[nv] = dist[v] + 1;

                q.push(nv);
            }
        }
    }

    int res = dist[1];

    if(res == INF) res = -1;

    cout << res << endl;

    return 0;
}