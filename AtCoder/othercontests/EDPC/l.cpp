#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<ll> a;
ll dp[3300][3300];
const ll INF = 1ll<<60;

ll rec(int l, int r){
    if(dp[l][r] != 0) return dp[l][r];
    if(l == r) return 0;
    // if(r-l == 1) return dp[l][r] = a[l];

    ll ret;
    if(n%2 == (r-l)%2){ // first
        ret = max(rec(l+1, r)+a[l], rec(l, r-1)+a[r-1]);
    }
    else{ // second
        ret = min(rec(l+1, r)-a[l], rec(l, r-1)-a[r-1]);
    }

    return dp[l][r] = ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    cout << rec(0, n) << endl;

    // rep(i, n+1){
    //     rep(j, n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    

    return 0;
}