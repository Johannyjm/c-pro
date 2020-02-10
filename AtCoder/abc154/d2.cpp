#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<double> e(n);
    rep(i, n) {
        double p;
        cin >> p;
        e[i] = 1.0 + 0.5*(p-1);
    }

    double res = 0.0;
    rep(i, k) res += e[i];

    double sum = res;
    rep(i, n-k){
        sum -= e[i];
        sum += e[k+i];

        res = max(res, sum);
    }

    printf("%.19f\n", res);

    return 0;
}