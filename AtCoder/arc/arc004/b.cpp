#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> d(n);
    int mx = 0;
    int res_mx = 0;
    rep(i, n){
        cin >> d[i];
        res_mx += d[i];
        mx = max(mx, d[i]);
    }

    cout << res_mx << endl;
    if(mx > res_mx-mx){
        cout << mx - (res_mx-mx) << endl;
    }
    else cout << 0 << endl;





    return 0;
}