#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<double> x, y, r;
double calc_dist(int i, int j){
    return pow(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2), 0.5);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    x.resize(n+m);
    y.resize(n+m);
    r.resize(n);

    rep(i, n+m){
        if(i < n) cin >> x[i] >> y[i] >> r[i];
        else cin >> x[i] >> y[i];
    }

    double res = 1001001001.0d;
    rep(i, n+m){
        rep(j, n+m){
            if(i <= j) continue;
            
            if(i<n && j<n) res = min({res, r[i], r[j]});
            
            else{
                double dist = calc_dist(i, j);
                double min_radius;

                if(i<n && j>=n) min_radius = min(dist-r[i], r[i]);
                else if(i>=n && j<n) min_radius = min(dist-r[j], r[j]);
                else min_radius = dist/2;

                res = min(res, min_radius);
            }
        }
    }

    printf("%.10f\n", res);

    return 0;
}