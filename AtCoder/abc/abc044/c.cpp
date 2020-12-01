#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    vector<vector<int>> dp(n, vector<int>(2750, 0));
    vector<map<int, ll>> cnt(2750);
    
    rep(i, n){
        dp[i][x[i]] = 1;

        if(i == 0){
            cnt[x[i]][1] += 1;
            continue;
        }

        vector<map<int, ll>> mp(2750);
        mp[x[i]][1] += 1;

        rep(j, 2750){
            if(dp[i-1][j] > 0) dp[i][j] = 1;
            if(j-x[i] >= 0 && dp[i-1][j-x[i]] > 0){
                dp[i][j] = 1;
                
                for(auto e: cnt[j-x[i]]){
                    mp[j][e.first+1] += e.second;
                }
            }
        }
        rep(j, 2750){
            for(auto e: mp[j]){
                cnt[j][e.first] += e.second;
            }
        }
    }

    ll res = 0;
    rep(i, 2750){
        for(auto e: cnt[i]){
            if(i%e.first == 0 && i/e.first == a){
                res += e.second;
            }
        }
    }

    cout << res << endl;

    return 0;
}