#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<double> a(n), b(n);

    double l = 0;
    rep(i, n){
        cin >> a[i] >> b[i];
        l += a[i];
    }

    double ok = 0;
    double ng = l;

    rep(i, 1000){
        double mid = (ok + ng) / 2;

        double left = 0;
        double now = 0;
        rep(j, n){
            now += a[j];
            if(now > mid){
                left += (a[j] - (now - mid)) / b[j];
                break;
            }
            else{
                left += a[j] / b[j];
            }
        }

        double right = 0;
        now = l;
        for(int j = n-1; j >= 0; --j){
            now -= a[j];
            if(now < mid){
                right += (a[j] - (mid - now)) / b[j];
                break;
            }
            else{
                right += a[j] / b[j];
            }
        }

        if(left > right){
            ng = mid;
        }
        else{
            ok = mid;
        }
    }

    cout << setprecision(20);
    cout << ok << endl;
    

    return 0;
}