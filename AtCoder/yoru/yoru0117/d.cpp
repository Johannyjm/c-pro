#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;
    rep(i, n-1){
        if(a[i] + a[i+1] <= x) continue;

        if(a[i] >= x){
            res += a[i+1];
            a[i+1] = 0;
            res += a[i] - x;
        }
        else{
            ll target = x - a[i];
            res += a[i+1] - target;
            a[i+1] = target;
        }
    }

    cout << res << endl;

    return 0;
}