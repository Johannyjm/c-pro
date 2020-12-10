#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double n, m, d;
    cin >> n >> m >> d;

    if(d == 0){
        double ex = 1/n;
        cout << setprecision(20);
        cout << ex*(m-1) << endl;
        return 0;
    }

    double ex = (2*n - 2*d) / n / n;
    
    
    cout << setprecision(20);

    cout << ex * (m-1) << endl;

    return 0;
}