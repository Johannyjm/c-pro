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
    
    vector<double> sm(22000, 0);
    rep(i, n){
        double s = r[i]*r[i]*h[i];
        int right = int(x[i] + h[i]);
        sm[right] += s;
        rep1(j, int(h[i])){
            double subcone = (double(j*j*j) * r[i]*r[i])/(h[i]*h[i]);
            sm[right-j] += s-subcone;
        }
    }


    cout << setprecision(20);
    rep(i, 30) cout << sm[i] << " ";
    cout << endl;
    rep(i, q){
        int a, b;
        cin >> a >> b;

        cout << M_PI*(sm[b] - sm[a])/3 << endl;
    }

    return 0;
}