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

    vector<vector<int>> g1(n, vector<int>(n, 0)), g2(n, vector<int>(n, 0));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g1[a][b] = 1;
        g1[b][a] = 1;
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g2[a][b] = 1;
        g2[b][a] = 1;
    }

    vector<int> order;
    rep(i, n) order.push_back(i);

    do{
        vector<vector<int>> g(n, vector<int>(n, 0));
        rep(i, n){
            rep(j, n){
                g[i][j] = g2[order[i]][order[j]];
            }
        }

        if(g == g1){
            puts("Yes");
            return 0;
        }
    } while(next_permutation(order.begin(), order.end()));

    puts("No");

    return 0;
}