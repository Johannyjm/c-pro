#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    vector<ll> d(m), c(m);
    ll D = 0;
    ll S = 0;
    rep(i, m){
        cin >> d[i] >> c[i];
        D += c[i];
        S += d[i] * c[i];
    }

    cout << D-1 + (S-1)/9 << endl;

    return 0;
}