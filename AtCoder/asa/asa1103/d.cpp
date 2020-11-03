#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll s;
    cin >> s;

    ll sqrt = pow(s, 0.5);
    sqrt = max(0ll, sqrt-100ll);
    while(sqrt*sqrt<s) ++sqrt;

    ll x2 = sqrt*sqrt-s;

    cout << 0 << " " << 0 << " " << 1 << " " << sqrt << " " << sqrt << " " <<  x2 << endl;

    return 0;
}