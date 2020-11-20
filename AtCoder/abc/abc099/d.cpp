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
    rep(i, c) rep(j, c) cin >> cost[i][j];
    vector<vector<int>> color(n, vector<int>(n));
    rep(i, n) rep(j, n){
        cin >> color[i][j];
        --color[i][j];
    }

    vector<int> mod0, mod1, mod2;
    rep(i, n) rep(j, n){
        if((i+j+2)%3 == 0) mod0.push_back(color[i][j]);
        if((i+j+2)%3 == 1) mod1.push_back(color[i][j]);
        if((i+j+2)%3 == 2) mod2.push_back(color[i][j]);
    }

    vector<pair<int, int>> cost0, cost1, cost2;
    rep(to, c){
        int sm = 0;
        for(auto e: mod0) sm += cost[e][to];
        cost0.push_back({sm, to});

        sm = 0;
        for(auto e: mod1) sm += cost[e][to];
        cost1.push_back({sm, to});
        
        sm = 0;
        for(auto e: mod2) sm += cost[e][to];
        cost2.push_back({sm, to});        
    }

    sort(cost0.begin(), cost0.end());
    sort(cost1.begin(), cost1.end());
    sort(cost2.begin(), cost2.end());

    int res = 1001001001;
    rep(i, 3) rep(j, 3) rep(k, 3){
        if(i>=(int)cost0.size() || j>=(int)cost1.size() || k>=(int)cost2.size()) continue;
        if(cost0[i].second == cost1[j].second) continue;
        if(cost1[j].second == cost2[k].second) continue;
        if(cost2[k].second == cost0[i].second) continue;
        
        int sm = cost0[i].first + cost1[j].first + cost2[k].first;
        
        res = min(res, sm);
    }

    cout << res << endl;

    return 0;
}