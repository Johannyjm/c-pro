#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(w+10, {0, 0}));
    int res = 0;
    for(int j = 1; j <= w; ++j){
        if(j >= a[0]) dp[0][j] = {b[0], 1};
        if(dp[0][j].second <= k) res = max(res, dp[0][j].first);
    }
    
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= w; ++j){
            int cand1 = dp[i-1][j].first;
            int cnt1 = dp[i-1][j].second;
            int cand2 = dp[i][j-1].first;
            int cnt2 = dp[i][j-1].second;
            int cand3 = -1;
            int cnt3 = 0;
            if(j-a[i] >= 0){
                cand3 = dp[i-1][j-a[i]].first + b[i];
                cnt3 = dp[i-1][j-a[i]].second + 1;
            }

            int mx = max({cand1, cand2, cand3});
            if(mx == cand1){
                if(cand1 == cand2) dp[i][j] = {mx, min(cnt1, cnt2)};
                else dp[i][j] = {mx, cnt1};
            }
            else if(mx == cand2) dp[i][j] = {mx, cnt2};
            else dp[i][j] = {mx, cnt3};

            if(dp[i][j].second <= k) res = max(res, dp[i][j].first);
        }
    }

    
    cout << res << endl;

    return 0;
}
