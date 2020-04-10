#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<double, double>> xy(n);
    rep(i, n){
        double x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    sort(xy.begin(), xy.end());

    int n_fact = 1;
    rep1(i, n+1) n_fact *= i;
    
    double sum = 0.0;
     
    do{
        pair<double, double> current = xy[0];
        double dist = 0.0;
        rep1(i, n){
            pair<double, double> nxt = xy[i];
            dist += pow((nxt.first - current.first) * (nxt.first - current.first) + (nxt.second - current.second) * (nxt.second - current.second), 0.5);
            current = xy[i];
        }

        sum += dist;

    } while(next_permutation(xy.begin(), xy.end()));

    printf("%.19f\n", sum / n_fact);


    return 0;
}