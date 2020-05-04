#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = -1001001001;
    for(int i = 0; i < n; ++i){
        int mx_aoki = -1001001001;
        int mx_idx = -1;
        int sum = 0;
        for(int j = 0; j < n; ++j){
            if(i==j) continue;
            
            int takahashi = 0;
            int aoki = 0;

            if(i<j){
                for(int k = i; k <= j; ++k){
                    if((k+i)%2==0) takahashi += a[k];
                    else aoki += a[k];
                }
            }
            else{
                for(int k = j; k <= i; ++k){
                    if((k+j)%2==0) takahashi += a[k];
                    else aoki += a[k];
                }
            }


            if(aoki > mx_aoki){
                mx_aoki = aoki;
                mx_idx = j;
                sum = takahashi;
            }
            // cout << endl;
            // cout << takahashi << " " << aoki << endl;

        }
        // cout << sum << endl;
        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}