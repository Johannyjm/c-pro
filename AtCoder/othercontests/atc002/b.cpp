#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll n, m, p;
ll modpow(ll n, ll p, ll m){
    if(p == 0) return 1;
    if(p == 1) return n;

    ll ret = modpow(n, p/2, m);
    if(p%2 == 0) return ret * ret % m;
    else return n%m * ret%m * ret%m;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> p;

    cout << modpow(n, p, m) << endl;


    return 0;
}