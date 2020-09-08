#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    int res = 0;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;

        res += min(x, k-x) * 2;
    }
    cout << res << endl;
}