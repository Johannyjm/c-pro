#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; ++i) cin >> d[i];

    sort(d, d + n);
    for (int i = 0; i < n; ++i) cout << d[i] << " ";

    cout << d[n/2] - d[n/2-1] << endl;
}