#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<ll> mymax(vector<ll> a, vector<ll> b){
    ll da = 0;
    ll db = 0;
    rep(i, 10){
        if(a[i] != -1) da += a[i];
        if(b[i] != -1) db += b[i];
    }

    if(da > db) return a;
    if(db > da) return b;

    for(int i = 9; i >= 1; --i){
        if(a[i] > b[i]) return a;
        if(b[i] > a[i]) return b;
    }

    return a;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> c(10);
    rep1(i, 10) cin >> c[i];

    vector<vector<ll>> dp(1100000, vector<ll>(10, -1));
    dp[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(ll i = 1; i*c[1] < 1100000; ++i){
        dp[c[1] * i] = {0, i, 0, 0, 0, 0, 0, 0, 0, 0}; 
    }

    vector<ll> init = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for(ll i = 2; i <= 10; ++i){
        rep(j, 1050000){
            if(j-c[i] >= 0 && dp[j-c[i]] != init){
                vector<ll> nxt = dp[j-c[i]];
                ++nxt[i];
                dp[j] = mymax(dp[j], nxt);
            }
        }
    }

    rep(i, 21){
        rep(j, 10) cout << dp[i][j] << " ";
        cout << endl;
    }

    int ptr = n;
    vector<ll> res_v = dp[n];
    while(res_v == init){
        --ptr;
        res_v = dp[ptr];
    }
    string res = "";
    for(int i = 9; i >= 1; --i){
        rep(j, res_v[i]) res += char('0' + i);
    }

    cout << res << endl;


    


    return 0;
}