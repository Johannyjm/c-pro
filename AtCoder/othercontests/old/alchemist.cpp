#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v, v + n);

    double res = v[0];
    for (int i = 0; i < n; ++i){
        res += v[i];
        res /= 2;
    }
    printf("%.5f\n", res);
}