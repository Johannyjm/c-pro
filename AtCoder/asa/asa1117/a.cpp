#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << max({a*c, a*d, b*c, b*d}) << endl;

    return 0;
}