#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    double min_digree = m*6;
    double hour_digree = 30*(n%12) + 30.*m/60.;
    double res = abs(min_digree - hour_digree);
    
    printf("%.10f\n", min(res, 180-res));
}