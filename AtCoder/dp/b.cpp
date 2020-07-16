#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    
    const int INF = 1001001001;
    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= k; ++j){
            if(i-j < 0) break;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    
    cout << dp[n-1] << endl;

}
