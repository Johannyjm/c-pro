#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double a, b, x;
    cin >> a >> b >> x;

    x /= a;

    if(x*2 < a*b){
        double rad = atan2(2*x, b*b);
        double degree = rad*180/M_PI;

        printf("%.10f\n", 90-degree);
    }
    else{
        double rad = atan2(2*b-((2*x)/a), a);
        double degree = rad*180/M_PI;

        printf("%.10f\n", degree);
    }

    return 0;
}