#include <bits/stdc++.h>
using namespace std;

int facc(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i) sum *= i;
    return sum;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    double x[n];
    double y[n];
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    double d = 0;

    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            d += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    double d_total = d * facc(n - 1) * 2;
    double route_total = facc(n);

    printf("%.10f\n", d_total / route_total);

}