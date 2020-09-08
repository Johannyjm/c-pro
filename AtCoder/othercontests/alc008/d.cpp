#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double w, h, x, y;
    cin >> w >> h >> x >> y;

    printf("%.19f", w*h/2);
    if(2*x == w && 2*y == h) puts(" 1");
    else puts(" 0");

    return 0;
}