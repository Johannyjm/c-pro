#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

const double pi = acos(-1);

double t, l, x, y;
int q;
double solve(ll e){
    double cy = -(l/2) * sin(2*pi*e/t);
    double cz = l/2 - (l/2) * cos(2*pi*e/t);
    
    double dist_h = sqrt(x*x + (y-cy) * (y-cy));
    double dist_v = cz;

    // cout << dist_h << " " << dist_v << endl;

    return atan2(dist_v, dist_h) * 180 / pi;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t >> l >> x >> y >> q;
    
    cout << setprecision(20);

    while(q--){
        ll e;
        cin >> e;

        cout << solve(e) << endl;
    }

    return 0;
}
