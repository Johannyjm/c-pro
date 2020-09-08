#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    double a, b, c, d, e;

    double res = -1;
    rep(i, n){
        cin >> a >> b >> c >> d >> e;
        res = max(res, a+b+c+d+e*110/900);
    }

    printf("%.15f\n", res);

    return 0;
}