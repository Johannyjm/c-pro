#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, k;

    cin >> a >> b >> c >> k;

    ll res = 0;
    if(k <= a) res = k;
    else if(a+b >= k) res = a;
    else{
        if(k <= a+b+c) res = a - (k-(a+b));
        else res = a-c;
    }

    cout << res << endl;


    return 0;
}