#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, k;
vector<double> w, p;
bool check(double d){
    vector<double> diff(n);
    rep(i, n){
        diff[i] = (p[i] - d) * w[i];
    }
    sort(diff.begin(), diff.end(), greater<double>());

    double sm = 0.0;
    rep(i, k) sm += diff[i];

    return sm >= 0.0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    w.resize(n);
    p.resize(n);
    rep(i, n) cin >> w[i] >> p[i];

    double ok = 0.0;
    double ng = 100.0;
    
    rep(_, 100){
        double mid = (ok+ng) / 2.0;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << setprecision(20);
    cout << ok << endl;

    return 0;
}