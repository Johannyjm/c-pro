#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    double res = 0;

    rep(i, n){
        double x;
        string u;
        cin >> x >> u;

        if(u == "BTC") res += 380000.0 * x;
        else res += x;
    }

    printf("%.10f\n", res);
}