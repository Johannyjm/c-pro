#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    string a, b;
    cin >> k >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ll base = 1;
    ll a10 = 0;
    ll b10 = 0;

    rep(i, (ll)a.size()){
        a10 += (a[i] - '0') * base;
        base *= k;
    }

    base = 1;
    rep(i, (ll)b.size()){
        b10 += (b[i] - '0') * base;
        base *= k;
    }

    cout << a10 * b10 << endl;



    return 0;
}