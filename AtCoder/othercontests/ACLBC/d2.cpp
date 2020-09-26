#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp;
    dp.push_back(a[0]);
    rep1(i, n){
        if(abs(a[i]-dp.back()) <= k) dp.push_back(a[i]);
        else{
            int idx1 = upper_bound(dp.begin(), dp.end(), a[i]-k) - dp.begin();
            int idx2 = lower_bound(dp.begin(), dp.end(), a[i]+k) - dp.begin();

            dp[min(idx1, idx2)] = a[i];
        }
        rep(j, dp.size()) cout << dp[j] << " ";
        cout << endl;
    }

    cout << dp.size() << endl;

    return 0;
}