#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n;
vector<char> c;
const ll mod = 10007;
vector<vector<ll>> dp;
ll solve(ll day, ll prev){
    if(day == n) return 1;
    if(dp[day][prev] > 0) return dp[day][prev];

    ll ret = 0;
    rep(i, 1<<3){
        if(!(i & (1<<c[day]))) continue;
        if((prev & i) == 0) continue;

        ret = (ret + solve(day+1, i) % mod) % mod;
    }

    dp[day][prev] = ret;
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> n >> s;

    c.resize(n);
    rep(i, n){
        if(s[i] == 'J') c[i] = 0;
        if(s[i] == 'O') c[i] = 1;
        if(s[i] == 'I') c[i] = 2;
    }

    dp.assign(n, vector<ll>(8, 0));
    
    ll res = 0;
    rep(i, 1<<3){
        if(!(i & (1<<0))) continue;
        if(!(i & (1<<c[0]))) continue;
        
        res = (res + solve(1, i)) % mod;
    }

    cout << res << endl;

    return 0;
}