#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, p;
    cin >> n >> p;

    mint res = mint(p-1) * mint(p-2).pow(n-1);

    cout << res.val() << endl;

    return 0;
}