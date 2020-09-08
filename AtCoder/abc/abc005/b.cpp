#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 101;
    rep(i, n){
        int t;
        cin >> t;

        res = min(t, res);
    }
    cout << res << endl;
}