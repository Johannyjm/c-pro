#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll a, b, c, d;
map<ll, ll> dp;
ll rec(ll n){

    if(dp[n] > 0) return dp[n];
    if(n == 0) return dp[n] = 0;
    if(n == 1) return dp[n] = d;
    if(n == 2) return dp[n] = min(d*2, a+d);
    if(n == 3) return dp[n] = min({d*3, a+2*d, a+b});
    if(n == 4) return dp[n] = min({d*4, 2*a+d, b+2*d, c+2*d});
    if(n == 5) return dp[n] = min({d*5, 2*a+2*d, a+b+2*d, c+d});

    ll ret = 1ll<<60;
    if(n%2 == 0) ret = min(ret, rec(n/2) + a);
    else{
        ret = min(ret, rec((n+1)/2) + a + d);
        ret = min(ret, rec((n-1)/2) + a + d);
    }

    if(n%3 == 0) ret = min(ret, rec(n/3) + b);
    else{
        int m = n%3;
        ret = min(ret, rec((n+(3-m))/3) + b + (3-m)*d);
        ret = min(ret, rec((n-m)/3) + b + m*d);
    }

    if(n%5) ret = min(ret, rec(n/5) + c);
    else{
        int m = n%5;
        ret = min(ret, rec((n+(5-m))/5) + c + (5-m)*d);
        ret = min(ret, rec((n-m)/5) + c + m*d);
    }

    return dp[n] = ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    rep(_, t){
        ll n;
        cin >> n >> a >> b >> c >> d;
        
        map<ll, ll> dp;
        ll res = rec(n);
        cout << res << "\n";
    }

    return 0;
}