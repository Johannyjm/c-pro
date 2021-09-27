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

    ll n, d;
    cin >> n >> d;
    vector<mint> dp(2200000, 0);

    mint one = 4; // 2
    mint now = 8;
    for(int i = 3; i <= n; ++i){
        one += now;
        now *= 2;
    }
    if(d == 1){
        cout << one.val() << endl;
        return 0;
    }

    if(n == 2){
        if(d == 1) cout << 4 << endl;
        else if(d == 2) cout << 2 << endl;
        else cout << 0 << endl;
        return 0;
    }

    mint fi = 2;
    fi = fi.pow(d - (1-d%2));

    



    return 0;
}