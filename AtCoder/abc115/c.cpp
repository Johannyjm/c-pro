#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int h[n];
    rep(i, n) cin >> h[i];

    sort(h, h+n);

    int res = 1e9;
    rep(i, n-k+1){
        res = min(res, h[i+k-1]-h[i]);
    }
    cout << res << endl;
}