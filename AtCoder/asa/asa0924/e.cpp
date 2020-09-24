#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1ll<<60;

ll n, a, b, c, d;
map<ll, ll> dp;
ll rec(ll num){
    if(dp[num] > 0) return dp[num];
    if(num == 0) return 0;
    if(num == 1) return dp[1] = d;
    ll ret = num*d;
    if(INF/num<d) ret = INF;

    ret = min(ret, d*(num%2) + a + rec(num/2));
    if(num%2 != 0) ret = min(ret, d*(2-num%2) + a + rec((num+(2-num%2))/2));

    ret = min(ret, d*(num%3) + b + rec(num/3));
    if(num%3 != 0) ret = min(ret, d*(3-num%3) + b + rec((num+(3-num%3))/3));

    ret = min(ret, d*(num%5) + c + rec(num/5));
    if(num%5 != 0) ret = min(ret, d*(5-num%5) + c + rec((num+(5-num%5))/5));
    
    return dp[num] = ret;
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
    }

    return 0;
}