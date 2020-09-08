#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    int a[n];
    rep(i, n) cin >> a[i];

    int res = 0;
    rep(i, q){
        int x, y;
        cin >> x >> y;

        rep(j, n){
            if(a[j]==x)a[j]=y;
        }


    }
    rep(i, n) res += a[i];
    cout << res << endl;
}