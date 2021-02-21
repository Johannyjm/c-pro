#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

double dp[330][330][330];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    rep(i, n){
        cin >> a[i];
        if(a[i] == 1) ++cnt1;
        if(a[i] == 2) ++cnt2;
        if(a[i] == 3) ++cnt3;
    }

   dp[1][0][0] = 3.0;
   dp[0][1][0] = 3.0;
   dp[0][0][1] = 3.0;

    rep1(i, 330){
        rep1(j, 330){
            rep1(k, 330){

                if(i+j+k > 0) dp[i][j][k] += n/(i+j+k);
                if(i > 1) dp[i][j][k] += dp[i-1][j][k] * i/(i+j+k);
                if(j > 1) dp[i][j][k] += dp[i][j-1][k] * j/(i+j+k);
                if(k > 1) dp[i][j][k] += dp[i][j][k-1] * k/(i+j+k);
            }
        }
    }

    cout << setprecision(20);
    cout << dp[cnt1][cnt2][cnt3] << endl;

    return 0;
}