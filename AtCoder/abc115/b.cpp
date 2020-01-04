#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int max_val = -1;
    int res = 0;

    rep(i, n){
        int p;
        cin >> p;

        max_val = max(max_val, p);
        res += p;
    }
    cout << res - max_val/2 << endl;
}