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

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    unordered_map<int, int> dp;
    int a;
    cin >> a;
    dp[a] = 1;
    int mx = 0;
    rep1(i, n){
        cin >> a;
        if(dp[a-1] != 0) dp[a] = dp[a-1] + 1;
        else dp[a] = 1;

        mx = max(mx, dp[a]);
    }

    cout << n - mx << endl;




    return 0;
}