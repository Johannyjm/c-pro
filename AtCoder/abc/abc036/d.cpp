#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int mod = 1000000007;

vector<ll> dpf;
vector<ll> dpg;
vector<vector<int>> g;
ll recg(int, int);

ll recf(int v, int prev){
    if(dpf[v] > 0) return dpf[v];

    ll white = recg(v, prev);
    ll black = 1;
    for(int nv: g[v]){
        if(nv == prev) continue;

        black = black * recg(nv, v) % mod;
    }
    
    return dpf[v] = (white + black) % mod;
}

ll recg(int v, int prev){
    if(dpg[v] > 0) return dpg[v];

    ll ret = 1;
    for(int nv: g[v]){
        if(nv == prev) continue;

        ret = (ret * recf(nv, v)) % mod;
    }

    return dpg[v] = ret;
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
    
    dpf.resize(n, 0);
    dpg.resize(n, 0);
    cout << recf(0, -1) << endl;

    return 0;
}
