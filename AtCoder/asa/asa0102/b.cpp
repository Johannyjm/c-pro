#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

double dist(double a, double b, double c, double d){
    return pow((a-c)*(a-c) + (b-d)*(b-d), 0.5); 
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    double res = 0;
    rep(i, n) rep(j, n){
        
        res = max(res, dist(x[i], y[i], x[j], y[j]));
    }

    cout << setprecision(20);
    cout << res << endl;


    return 0;
}