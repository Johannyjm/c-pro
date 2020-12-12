#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        ll n;

        cin >> n;
        if(n == 0) break;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        const int mod = 1000000007;

        ll x = (a + c) * (c-a+1) / 2 % mod;
        ll y = (b + d) * (d-b+1) / 2 % mod;

        cout << (x%mod*y%mod)%mod << endl;
    }


    return 0;
}