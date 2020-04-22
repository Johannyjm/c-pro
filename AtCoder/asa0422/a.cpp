#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n+1, 0);
    rep(i, m){
        int idx;
        cin >> idx;
        ++a[idx];
    }

    int r = 0;
    for(int i = x; i <= n; ++i) r += a[i];

    int l = 0;
    for(int i = x; i >= 0; --i) l += a[i];

    cout << min(l, r) << endl;

    return 0;
}