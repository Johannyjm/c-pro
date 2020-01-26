#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];

    int res = 0;
    rep(i, n){
        res += b[a[i]-1];
        if(a[i]+1 == a[i+1]) res += c[a[i] - 1];
    }

    cout << res << endl;

    return 0;
}