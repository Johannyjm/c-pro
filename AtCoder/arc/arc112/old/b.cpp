#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll b, c;
    cin >> b >> c;

    vector<set<ll>> dp(220);
    dp[0].insert(b);

    set<ll> res;
    rep(i, 200){
        for(auto e: dp[i]){
            dp[i+1].insert(-e);
            dp[i+2].insert(e-1);
        }
    }

    rep(i, 200){
        for(auto e: dp[i]){
            res.insert(e);
        }
        // cout << res.size() << " ";
        cout << i << ": " << res.size() << ", ";
        // for(auto e: res) cout << e << " ";
        cout << endl;
    }
    cout << endl;

    // rep(i, 22){
    //     cout << i << ": " << dp[i].size() << " , ";
    //     for(auto e: dp[i]) cout << e << " ";
    //     cout << endl;
    // }


    return 0;
}