#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 0;
    rep(l, n){
        int mn = a[l];
        rep(r, n){
            if(l > r) continue;
            mn = min(mn, a[r]);
            res = max(res, mn*(r-l+1));
        }
    }

    cout << res << endl;
    
    return 0;
}