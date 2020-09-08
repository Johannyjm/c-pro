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
    vector<double> r(n);
    rep(i, n) cin >> r[i];

    sort(r.begin(), r.end());
    double res = 0;
    for(int i = n-k; i<n; ++i){
        res = (res+r[i])/2;
    }
    printf("%.19f\n", res);

    return 0;
}