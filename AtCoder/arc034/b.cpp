#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int func(ll n){
    int ret = 0;
    while(n){
        ret += n%10;
        n /= 10;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    
    ll from = max(0ll, n - 200);
    ll to = n + 200;

    vector<ll> res;
    for(ll k = from; k < to; ++k){
        if(func(k) + k == n) res.push_back(k);
    }

    cout << res.size() << endl;
    rep(i, res.size()) cout << res[i] << endl;

    return 0;
}