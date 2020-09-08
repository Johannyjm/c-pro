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
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    vector<int> res(m, -1);
    vector<int> child(n, -1);

    // int r = 0;
    vector<int> dp;
    dp.push_back(a[0]);
    res[0] = 0;
    rep1(i, m){
        if(a[i] <= dp.back()) {
            dp.push_back(a[i]);
            res[i] = dp.size()-1;
        }
        else{

            int l = 0;
            int r = dp.size();
            while(abs(r-l) > 1){
                int mid = (r + l) / 2;
                cout << l << " " << r << " " << mid << endl;
                if(dp[mid] < a[i]) l = mid;
                else r = mid;
            } 
            dp[l] = a[i];
            res[i] = l;
            // int idx = upper_bound(dp.rbegin(), dp.rend(), a[i]) - dp.rbegin();
            // dp[idx] = a[i];
            // res[i] = idx;
            cout << "idx: " << l << endl;
        }
        rep(j, dp.size()) cout << dp[j] << " ";
        cout << endl;

        // int l = 0;
        // if(child[r] < a[i]) l = r;
        // else{
        //     while(abs(r-l) > 1){
        //         int m = (r+l) / 2;

        //         if(child[m] > a[i]) l = m;
        //         else r = m;
        //     }
        // }

        // cout << "l: " << l << endl;

        // for(int j = l; j < n; ++j){
        //     if(a[i] > child[j]){
        //         child[j] = a[i];
        //         res[i] = j+1;
        //         r = j;
        //         break;
        //     }
        // }
    }

    rep(i, m) cout << res[i] << endl;

    return 0;
}