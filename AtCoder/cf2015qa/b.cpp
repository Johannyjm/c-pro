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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 0;
    int base = n-1;
    rep(i, n){
        res += a[i] * pow(2, base);
        --base;
    }

    cout << res << endl;

    return 0;
}