#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double a, b, x;
    cin >> a >> b >> x;

    if(x / (a * a) <= b / 2) printf("%.10lf\n", 90 - atan(2 * x / (a * b * b)) * 180 / M_PI);
    else printf("%.10lf\n", atan(2 * b / a - 2 * x / (a * a * a)) * 180 / M_PI);
}