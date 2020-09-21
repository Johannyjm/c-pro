#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int sm = 0;
        rep(i, n){
            cin >> a[i];
            sm += a[i];
        }

        bool flg = false;
        for(int i = 0; i < n-2; ++i){
            for(int j = i+1; j < n-1; ++j){
                int J = 0;
                for(int ii = 0; ii <= i; ++ii) J += a[ii];
                int O = 0;
                for(int ii = i+1; ii <= j; ++ii) O += a[ii];
                int I = sm - J - O;

                if(J == O && O == I) flg = true;
            }
        }

        if(flg) puts("Yay!");
        else puts(":(");
    }


    return 0;
}