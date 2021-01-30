#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<double> x(n), r(n), h(n);
    rep(i, n) cin >> x[i] >> r[i] >> h[i];

    vector<double> sm(22000, 0), imos(22000, 0);
    rep(i, n){
        double s = r[i] * r[i] * M_PI * h[i] / 3;
        imos[int(x[i]+h[i])+1] += s;
        rep(j, int(h[i])){
            double subr = r[i]*(h[i]-j-1)/h[i];
            sm[int(x[i])+j+1] += s - subr*subr*M_PI*(h[i]-j-1)/3;
        }
    }
    rep(i, 21000) imos[i+1] += imos[i];
    rep(i, 22000) sm[i] += imos[i];

    cout << setprecision(20);
    rep(i, q){
        int a, b;
        cin >> a >> b;

        cout << sm[b] - sm[a] << endl;
    }

    return 0;
}