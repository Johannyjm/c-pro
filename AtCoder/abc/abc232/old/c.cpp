#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g1(n), g2(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;

        --a;
        --b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }

    rep(i, m){
        int a, b;
        cin >> a >> b;
        
        --a;
        --b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    rep(i, n){
        sort(g1[i].begin(), g1[i].end());
    }

    vector<int> order;
    rep(i, n) order.push_back(i);

    do{
        vector<vector<int>> g(n);
        rep(i, n){
            rep(j, (int)g2[order[i]].size()) g[i].push_back(g2[order[i]][j]);
        }

        rep(i, n){
            sort(g[i].begin(), g[i].end());
        }

        if(g == g1){
            puts("Yes");
            return 0;
        }

    } while(next_permutation(order.begin(), order.end()));

    puts("No");

    return 0;
}