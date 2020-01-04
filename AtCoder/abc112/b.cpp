#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, T;
    cin >> n >> T;

    int res = 1001;
    rep(i, n){
        int c, t;
        cin >> c >> t;
        if(t <= T){
            res = min(res, c);
        }
    }

    if(res<1001) cout << res << endl;
    else cout << "TLE" << endl;
}