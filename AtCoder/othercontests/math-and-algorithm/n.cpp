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

    map<ll, ll> res;
    for(ll k = 2; k*k <= n; ++k){
        while(n%k == 0){
            n /= k;
            ++res[k];
        }
    }
    if(n != 1) res[n] = 1;

    for(auto k: res){
        rep(_, k.second) cout << k.first << " ";
    }
    cout << endl;

    return 0;
}