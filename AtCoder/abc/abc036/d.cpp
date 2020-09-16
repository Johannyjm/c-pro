#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000000007;

vector<ll> calc_fib(ll n){
    vector<ll> ret(n+10);
    ret[0] = 1;
    ret[1] = 1;
    for(int i = 2; i < n+10; ++i){
        ret[i] = (ret[i-2] + ret[i-1]) % mod;
    }

    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sycn_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<ll> fib(n+10) = calc_fib(n);

    vector<vector<int>> g(n);
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int start;
    for(int i = 0; i < n; ++i){
        if(g[i].size() == 1){
            start = i;
            break;
        }
    }

    cout << dfs(start) << endl;
    
    return 0;
}
