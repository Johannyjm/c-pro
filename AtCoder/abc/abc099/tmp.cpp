#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<vector<int>> cost(c, vector<int>(c));
    vector<int> costmn(c, 1001001001);
    rep(i, c) rep(j, c){
        cin >> cost[i][j];
        if(i!=j) costmn[i] = min(costmn[i], cost[i][j]);
    }
    vector<vector<int>> color(n, vector<int>(n));
    rep(i, n) rep(j, n){
        cin >> color[i][j];
        --color[i][j];
    }

    vector<vector<int>> cmod(3, vector<int>(c, 0));
    vector<unordered_set<int>> use(3, unordered_set<int>());
    rep(i, n) rep(j, n){
        ++cmod[(i+j+2)%3][color[i][j]];
        use[(i+j+2)%2].insert(color[i][j]);
    }


    rep(i, 3){
        rep(j, c) cout << cmod[i][j] << " ";
        cout << endl;
    }
    for(auto e: costmn) cout << e << " ";
    cout << endl;

    int res = 1001001001;
    for(auto zero: use[0]){
        for(auto one: use[1]){
            for(auto two: use[2]){
                
            }
        }
    }


    return 0;
}