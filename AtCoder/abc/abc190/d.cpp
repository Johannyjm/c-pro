#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            ret.insert(i);
            if(i*i != n) ret.insert(n/i);
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    set<ll> d = divisor(n*2);
    // for(auto e: d) cout << e << " ";
    // cout << endl;

    int res = 0;
    for(ll a: d){
        ll b = (2*n)/a;
        if((a+b-1)%2==0 && (a-b+1)%2==0 && a-b+1<=a+b-1){
            // cout << a << " " << b << " " << (a-b+1)/2 << " " << (a+b-1)/2 << endl;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}