#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 1;
    for(ll k = 1; k <= n; ++k) res *= k;

    cout << res << endl;

    return 0;
}