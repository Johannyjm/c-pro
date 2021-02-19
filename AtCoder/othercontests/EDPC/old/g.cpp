#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }

    vector<int> dp(n, 0);
    queue<int> q;
    for(int st = 0; st < n; ++st){
        if(dp[st] != 0) continue;
        q.push(st);
        
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int nv: g[v]){
                if(dp[nv] < dp[v] + 1){
                    dp[nv] = dp[v] + 1;
                    q.push(nv);
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        if(res < dp[i]) res = dp[i];
    }

    cout << res << endl;

    return 0;
}
