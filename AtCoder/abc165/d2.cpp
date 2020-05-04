#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll a, b;
ll func(ll x){
    return a*x/b - a*(x/b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> a >> b >> n;

    if(n<b) cout << func(n) << endl;
    else cout << func(b-1) << endl;

    return 0;
}