#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double w, h, x, y;
    cin >> w >> h >> x >> y;

    double res = h*w/2;
    int resflg;

    if(x*2 == w && y*2 == h) resflg = 1;
    else resflg = 0;

    printf("%.10f%s%d\n", res, " ", resflg);

}