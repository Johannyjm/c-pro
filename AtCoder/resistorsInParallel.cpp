#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    double res = 0;
    for (int i = 0; i < n; ++i){
        res += 1.0/a[i];
    }
    printf("%.10f\n", 1/res);
}