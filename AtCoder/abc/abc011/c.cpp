#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    const int INF = 1001001001;
    vector<int> dp(n+1, INF);
    dp[n] = 0;
    for(int i = n-1; i >= 0; --i){
        if(i==a || i==b || i==c) continue;
        dp[i] = dp[i+1] + 1;
        if(i+2 <= n) dp[i] = min(dp[i], dp[i+2] + 1);
        if(i+3 <= n) dp[i] = min(dp[i], dp[i+3] + 1);
    }

    if(dp[0] <= 100) cout << "YES" << endl;
    else cout << "NO" << endl;

    for(auto e: dp) cout << e << " ";
    cout << endl;

    return 0;
}
