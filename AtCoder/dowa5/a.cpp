#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double n;
    cin >> n;
    double sum = 0;
    vector<double> a(n);
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }

    double ave = sum / n;
    double min_d = 101;
    int res = 0;
    rep(i, n){
        if(abs(ave - a[i]) < min_d){
            min_d = abs(ave - a[i]);
            res = i;
        }
    }

    cout << res << endl;

    return 0;
}