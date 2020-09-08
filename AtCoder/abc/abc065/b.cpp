#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n];
    rep(i, n) cin >> a[i];

    int ptr = 0;
    int res = 0;
    bool flg = false;

    rep(i, 2*n){
        if(a[ptr]==2){
            ++res;
            flg = true;
            break;
        }
        ptr = a[ptr]-1;
        ++res;
    }

    if(flg) cout << res << endl;
    else cout << -1 << endl;
}