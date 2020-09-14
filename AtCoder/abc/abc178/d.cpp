#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll dp[2200];
vector<vector<bool>> seen;
ll rec(ll s){

    ll ret = 0;
    for(ll i = 3; i <= s-3; ++i){
        // ret = (ret + rec(i)) % mod;
        // ret = (ret + rec(s-i)) % mod;
        if(seen[i][s-i]) continue;
        seen[i][s-i] = true;
        if(i >= 6) ret = (ret + rec(i)) % mod;
        if(s-i >= 6) ret = (ret + rec(s-i)) % mod;
        ret = (ret + 1) % mod;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll s;
    cin >> s;
    seen.resize(s+1, vector<bool>(s+1, false));

    if(s < 3){
        cout << 0 << endl;
        return 0;
    }

    cout << rec(s) << endl;

    return 0;
}