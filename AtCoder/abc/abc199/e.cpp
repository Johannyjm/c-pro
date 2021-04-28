#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
vector<pair<int, int>> conts;
ll dp[1<<19][19];

ll rec(ll s, ll v){
    if(dp[s][v] != 0) return dp[s][v];
    if(s == (1<<n)-1) return dp[s][v] = 1;

    ll ret = 0;
    for(ll nv = 0; nv < n; ++nv){
        if(s & (1<<nv)) continue;
        
    }
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    conts.resize(n);
    for(int i = 0; i < m; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        conts[x].push_back({y, z});
    }

    ll res = rec(0, 0);

    cout << res << endl;
    

    return 0;
}
