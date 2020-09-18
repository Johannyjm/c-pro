#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int mod = 1000000007;
vector<vector<int>> g;
vector<vector<ll>> dp;

ll rec(int v, int c, int prev){ // c: 0-white, 1-black
    if(dp[v][c] > 0) return dp[v][c];
    
    if(c == 1){
        ll ret = 1;
        for(int nv: g[v]){
            if(nv == prev) continue;
            ret = (ret * rec(nv, 0, v)) % mod;
        }

        return dp[v][c] = ret;
    }

    else{
        ll white = 1;
        ll black = 1;
        for(int nv: g[v]){
            if(nv == prev) continue;
            white = (white * rec(nv, 0, v)) % mod;
            black = (black * rec(nv, 1, v)) % mod;
        }

        return dp[v][c] = (white + black) % mod;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    g.resize(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dp.resize(n, vector<ll>(2, 0));

    cout << rec(0, 0, -1) << endl; //(rec(0, 0, -1) + rec(0, 1, -1)) % mod << endl;

    return 0;
}
