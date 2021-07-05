#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll p;
    cin >> p;
    int res = 0;

    vector<ll> fac;
    ll now = 1;
    rep1(i, 11){
        now *= i;
        fac.push_back(now);
        // cout << fac.back() << endl;
    }

    reverse(fac.begin(), fac.end());

    for(auto f: fac){
        // cout << f << endl;
        while(p >= f){
            p -= f;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}