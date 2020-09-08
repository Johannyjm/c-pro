#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    rep(i, n){
        int l, r;
        cin >> l >> r;

        res += r - l + 1;
    }
    cout << res << endl;
}