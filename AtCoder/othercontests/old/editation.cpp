#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    int res[n] = {0};
    rep(i, q){
        int l, r;
        cin >> l >> r;
        --l;
        int t;
        cin >> t;
        for (int j = l; j < r; ++j){
            res[j] = t;
        }
    }
    rep(i, n) cout << res[i] << endl;

}