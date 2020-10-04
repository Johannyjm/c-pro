#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> dp(n+1, 0);
    rep(_, q){
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        ++dp[l];
        --dp[r+1];
    }

    rep1(i, n+1) dp[i] += dp[i-1];

    // rep(i, n+1) cout << dp[i] << " ";
    // cout << endl;
    rep(i, n){
        if(dp[i]%2 == 0) cout << 0;
        else cout << 1;
    }
    cout << endl;

    return 0;
}