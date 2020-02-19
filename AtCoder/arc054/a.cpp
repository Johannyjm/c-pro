#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double l, x, y, s, d, res;
    cin >> l >> x >> y >> s >> d;

    if(x>=y){
        if(s < d) res = (d-s) / (y+x);
        else res = (l-s+d) / (y+x);
    }

    else{
        if(s < d) res = min((d-s) / (y+x), (s+l-d) / (y-x));
        else res = min((s-d) / (y-x), (l-s+d) / (y+x));
    }
    
    printf("%.19f\n", res);

    return 0;
}