#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll tmp = n;
    int d = 0;
    while(tmp){
        ++d;
        tmp /= 10;
    }

    mint res = 0;
    mint now = 9;
    rep1(i, d){
        res += (1 + now) * now / 2;
        now *= 10;
    }

    ll sub = 1;
    rep1(i, d) sub *= 10;
    mint remain = n - sub;
    
    res += (1 + remain+1) * (remain+1) / 2;

    cout << res.val() << endl;

    return 0;
}