#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double min_d2(double x0, double y0, double x1, double y1, double x2, double y2){
    double a = x2 - x1;
    double b = y2 - y1;
    double a2 = a * a;
    double b2 = b * b;
    double r2 = a2 + b2;
    double tt = -(a*(x1-x0) + b*(y1-y0));

    if(tt < 0) return (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
    if(tt > r2) return (x2-x0)*(x2-x0) + (y2-y0)*(y2-y0);
    
    double f1 = a*(y1-y0) - b*(x1-x0);

    return (f1*f1) / r2;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double x0, y0;
    int n;
    cin >> x0 >> y0 >> n;
    vector<double> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    
    double res = min_d2(x0, y0, x[0], y[0], x[n-1], y[n-1]);
    for(int i = 1; i < n; ++i) res = min(res, min_d2(x0, y0, x[i], y[i], x[i-1], y[i-1]));

    cout << setprecision(20);
    cout << pow(res, 0.5) << endl;


    return 0;
}
