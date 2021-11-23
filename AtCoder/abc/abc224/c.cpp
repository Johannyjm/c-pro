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
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int res = 0;
    rep(i, n) rep(j, n) rep(k, n){
        if(!(i < j && j < k)) continue;

        if((y[j]-y[i])*(x[k]-x[i]) == (y[k]-y[i])*(x[j]-x[i])) continue;

        ++res;
    }

    cout << res << endl;

    return 0;
}