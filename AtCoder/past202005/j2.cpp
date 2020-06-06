#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> sushi(m);
    rep(i, m) {
        cin >> sushi[i];
        sushi[i] *= -1;
    }


    vector<int> dp;
    dp.push_back(sushi[0]);
    vector<int> res(m, -1);
    res[0] = 1;

    rep1(i, m){
        if(sushi[i] >= dp.back()){
            dp.push_back(sushi[i]);
            res[i] = dp.size();
        }
        else{
            int idx = upper_bound(dp.begin(), dp.end(), sushi[i]) - dp.begin();
            dp[idx] = sushi[i];
            res[i] = idx+1;
        }

        // rep(j, dp.size()) cout << dp[j] << " ";
        // cout << endl;
    }

    rep(i, m){
        if(res[i] <= n) cout << res[i] << endl;
        else cout << -1 << endl;
    }

    return 0;
}