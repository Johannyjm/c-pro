#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n], b[n], c[n-1];

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n-1; ++i) cin >> c[i];

    int sum = b[a[0] - 1];
    for (int i = 1; i < n; ++i){
        sum += b[a[i] - 1];

        if(a[i] == a[i - 1] + 1) sum += c[a[i - 1] - 1];
    }
    cout << sum << endl;

}