#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 1e9;

    for(int i = 1; i*i <= n; ++i){
        int j = n / i;
        int r = n - i * j;
        int d = j-i;
        res = min(res, r+d);
    }

    cout << res << endl;
}