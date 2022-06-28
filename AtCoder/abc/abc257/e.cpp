#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> c(10);
    rep1(i, 10) cin >> c[i];

    vector<vector<ll>> dp(1100000, vector<ll>(10, -1));
    dp[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(ll i = 1; i*c[i] < 1100000; ++i){
        dp[c[1] * i] = {0, i, 0, 0, 0, 0, 0, 0, 0, 0}; 
    }

    vector<ll> init = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for(ll i = 2; i <= 10; ++i){
        rep(j, 1050000){
            if(j-c[i] >= 0 && dp[j-c[i]] != init){
                dp[j] = mymax(dp[j], ++dp[j-c[i]][i]);
            }
        }
    }

    string res = "";
    


    return 0;
}