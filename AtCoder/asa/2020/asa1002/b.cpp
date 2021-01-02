#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a_, b_;
    cin >> a_ >> b_;
       
    int res = a_-b_;
    int a1_ = a_/100;
    int a2_ = a_/10%10;
    int a3_ = a_%10;

    int b1_ = b_/100;
    int b2_ = b_/10%10;
    int b3_ = b_%10;
    for(int a = 100; a <= 999; ++a) for(int b = 100; b <= 999; ++b){

        // res = max({res, a%100 + 900 - b, a - (b%100 + 100)});
        int a1 = a/100;
        int a2 = a/10%10;
        int a3 = a%10;

        int b1 = b/100;
        int b2 = b/10%10;
        int b3 = b%10;

        if(a1 == 0 || b1 == 0) continue;

        int cnt = 0;
        if(a1 != a1_) ++cnt;
        if(a2 != a2_) ++cnt;
        if(a3 != a3_) ++cnt;
        if(b1 != b1_) ++cnt;
        if(b2 != b2_) ++cnt;
        if(b3 != b3_) ++cnt;
        
        if(cnt == 1) res = max(res, a-b);
    }
    cout << res << endl;
    return 0;
}