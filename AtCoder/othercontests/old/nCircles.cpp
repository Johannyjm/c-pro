#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int r[n];
    rep(i, n) cin >> r[i];
    sort(r, r+n, greater<int>());

    double res = 0.;
    rep(i, n){
        if(i%2) res -= r[i]*r[i];
        else res += r[i]*r[i];
    }

    printf("%.12f\n", res * M_PI);


}