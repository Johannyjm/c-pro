#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, a, b, c, d;
map<ll, ll> dp;
const ll INF = 1ll<<60;

ll rec(ll x){
    if(dp[x] > 0) return dp[x];
    if(x == 0) return dp[0] = 0;
    if(x == 1) return dp[1] = d;

    ll ret = x*d;
    ll cost1 = INF;
    ll cost2 = INF;
    if(INF/d > x) ret = INF;
    // ll cost1 = d*(x - (x/2));
    // if(INF/d > x-(x/2)) cost1 = INF;
    // ll cost2 = d*(x - (x-1)/2);
    // if(INF/d > x-(x-1)/2) cost2 = INF;

    if(x%2 == 0) ret = min({ret, a+rec(x/2), cost1});
    else ret = min({ret, a+d+rec((x+1)/2), a+d+rec((x-1)/2), cost2});

    // cost1 = d*(x - (x/3));
    // if(INF/d > x-(x/3)) cost1 = INF;
    // cost2 = d*(x - (x-x%3)/3);
    // if(INF/d > x-(x-x%3)/3) cost2 = INF;
    if(x%3 == 0) ret = min({ret, b+rec(x/3), cost1});
    else ret = min({ret, b+d*(3-x%3)+rec((x+(3-x%3))/3), b+d*(x%3)+rec((x-x%3)/3), cost2});

    // cost1 = d*(x - (x/5));
    // if(INF/d > x-(x/5)) cost1 = INF;
    // cost2 = d*(x - (x-x%5)/5);
    // if(INF/d > x-(x-x%5)/5) cost2 = INF;
    if(x%5 == 0) ret = min({ret, c+rec(x/5), cost1});
    else ret = min({ret, c+d*(5-x%5)+rec((x+(5-x%5))/5), c+d*(x%5)+rec((x-x%5)/5), cost2});

    return dp[x] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while(t--){
        cin >> n >> a >> b >> c >> d;

        dp.clear();
        cout << rec(n) << endl;
        // for(auto k: dp) cout << k.first << ":" << k.second << " ";
        cout << endl;
    }

    return 0;
}