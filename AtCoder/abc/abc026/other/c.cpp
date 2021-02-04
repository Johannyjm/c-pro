#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double a, b, c;
    cin >> a >> b >> c;

    auto f = [&](double t){
        return a*t + b*sin(c*t*M_PI) - 100;
    };
    auto g = [&](double t){
        return a*t + b*sin(c*t*M_PI);
    };

    double l = max(0.0, (100.0-b)/a);
    double r = (100.0+b)/a;
    double prev = f(l);
    double eps = (r-l)/1000000;
    for(double d = l; d <= r; d += eps){
        if(prev * f(d) < 0){
            l = d-eps;
            r = d;
            break;
        }

        prev = f(d);
    }

    while(abs(r-l) > 0.0000000001){
        double mid = (r+l) / 2;

        if(f(r) * f(mid) < 0) l = mid;
        else r = mid;
    }

    cout << setprecision(20);
    cout << r << endl;

    // cout << g(r) << endl;

    return 0;
}