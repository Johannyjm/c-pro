#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = -1001001001;
    rep(ta, n){
        int a_mx = -1001001001;
        // int a_choice = -1;
        int sm = -1001001001;
        rep(ao, n){
            if(ao == ta) continue;
            int takahashi = 0;
            int aoki = 0;

            int cnt = 0;
            if(ao < ta){
                for(int i = ao; i <= ta; ++i){
                    if(cnt%2 == 0) takahashi += a[i];
                    else aoki += a[i];
                    ++cnt;
                }
            }
            else{
                for(int i = ta; i <= ao; ++i){
                    if(cnt%2 == 0) takahashi += a[i];
                    else aoki += a[i];
                    ++cnt;
                }
            }

            if(aoki > a_mx){
                a_mx = aoki;
                // a_choice = ao;
                // cout << ta << " " << ao << " " << takahashi << " " << aoki << endl;
                sm = takahashi;
            }
        }
        res = max(res, sm);
    }

    cout << res << endl;

    return 0;
}