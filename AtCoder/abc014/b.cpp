#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    int a[n];
    rep(i, n) cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; ++i){
        if(x & (1<<i)){
            res += a[i];
        }
    }
    cout << res << endl;
}