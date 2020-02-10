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
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    double res = 0.0;
    rep(i, n-k){
        double sum = 0;
        for(int j = i; j < i+k; ++j){
            sum += 1 + 0.5*(p[j]-1);
        }
        res = max(res, sum);
    }

    printf("%.19f\n", res);

    return 0;
}