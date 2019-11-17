#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    double x[n], y[n];
    int indices[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        indices[i] = i;
    }

    double d_total = 0;
    int count = 0;

    do {
        for (int i = 0; i < n - 1; ++i){
            int begin = indices[i];
            int end = indices[i + 1];
            d_total += sqrt((x[begin] - x[end]) * (x[begin] - x[end]) + (y[begin] - y[end]) * (y[begin] - y[end]));
        }
        count++;
    } while(next_permutation(indices, indices + n));

    printf("%.10f\n", d_total / count);


}