#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n);
    dsu uf(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.merge(a, b);
    }

    for(auto group: uf.groups()){

        if((int)group.size() == 1) continue;
        
        int rank1 = 0;
        int rank2 = 0;
        for(auto v: group){
            if((int)g[v].size() == 1) ++rank1;
            else if((int)g[v].size() == 2) ++rank2;
            else{
                puts("No");
                return 0;
            }

        }
        
        if(!(rank1 == 2 && rank2 == (int)group.size() - 2)){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}
