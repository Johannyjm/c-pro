// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    double res = 0.0;
    rep1(k, n+1){
        res += (double)(10000 * k) / n;
    }    

    cout << setprecision(20);
    cout << res << endl;

    return 0;
}