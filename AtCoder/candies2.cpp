#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a1[n], a2[n];

    for (int i = 0; i < n; ++i) cin >> a1[i];
    for (int i = 0; i < n; ++i) cin >> a2[i];

    int res = -1;
    for (int i = 0; i < n; ++i){
        int candies = 0;
        for (int j = 0; j <= i; ++j) candies += a1[j];
        for (int j = i; j < n; ++j) candies += a2[j];

        res = max(res, candies);
    }
    cout << res << endl;
}