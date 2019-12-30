#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l, h, n;
    cin >> l >> h >> n;

    rep(i, n){
        int a;
        cin >> a;

        if(a < l) cout << l-a << endl;
        else if(l <= a && a <= h) cout << 0 << endl;
        else cout << -1 << endl;
    }
}