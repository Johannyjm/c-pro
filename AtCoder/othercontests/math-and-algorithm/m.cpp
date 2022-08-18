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

    unordered_set<ll> res;
    for(ll k = 1; k*k <= n; ++k){
        if(n%k == 0){
            res.insert(k);
            res.insert(n/k);
        }
    }

    for(auto e: res) cout << e << endl;

    return 0;
}