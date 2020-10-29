#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    double t, a;
    cin >> t >> a;

    int res = -1;
    double mn_diff = 1001001001;
    rep(i, n){
        double h;
        cin >> h;

        double temp = t - 0.006*h;
        
        if(abs(a - temp) < mn_diff){
            mn_diff = abs(a - temp);
            res = i+1;
        }        
    }
    

    cout << res << endl;

    return 0;
}