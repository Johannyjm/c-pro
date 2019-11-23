#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int b[n-1];
    for (int i = 0; i < n-1; ++i) cin >> b[i];

    int res = b[0] + b[n-2];
    for (int i = 1; i < n-1; ++i){
        res += min(b[i-1], b[i]);
    }

    cout << res << endl;
}