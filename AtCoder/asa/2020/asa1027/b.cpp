#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, l, p, q, r;
    cin >> n >> m >> l >> p >> q >> r;

    int res = (n/p) * (m/q) * (l/r);
    
    res = max(res, (n/p)*(m/r)*(l/q));
    res = max(res, (n/q)*(m/p)*(l/r));
    res = max(res, (n/q)*(m/r)*(l/p));
    res = max(res, (n/r)*(m/p)*(l/q));
    res = max(res, (n/r)*(m/q)*(l/p));
    
    cout << res << endl;

    return 0;
}