#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

double p;

double calc_cost(double x){
    double ability = pow(2, x/1.5);
    return x + p/ability;
}

double calc_cost_dif(double x){
    return 1 - (p*M_LN2 / 1.5 / pow(2, x/1.5));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> p;

    double l = 0;
    double r = p*10;

    if(calc_cost_dif(l) > 0){
        cout << setprecision(12) << calc_cost(l) << endl;
        return 0;
    }

    while(abs(r-l) > 0.00000001){
        double m = (l + r) / 2.;
        if(calc_cost_dif(m) > 0) r = m;
        else l = m;
    }

    cout << setprecision(12) << calc_cost(l) << endl;


    return 0;
}