#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int x[m];
    rep(i, m) {
        cin >> x[i];
    }

    sort(x, x+m);
    int diff[m-1];
    rep1(i, m) diff[i-1] = x[i]-x[i-1];
       
    sort(diff, diff+m-1, greater<int>());
    int res = 0;
    rep(i, m-1) {
        if(i < n-1) res += 0;
        else res += diff[i];
    }

    cout << res << endl;
}