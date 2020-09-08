#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    int res = 0;
    for(int i = 0; i < n-2; ++i){
        for(int j = i+1; j < n-1; ++j){
            for(int k = j+1; k < n; ++k){
                ll x1 = x[j] - x[i];
                ll x2 = x[k] - x[i];
                ll y1 = y[j] - y[i];
                ll y2 = y[k] - y[i];

                ll s2 = abs(x1*y2 - x2*y1);

                if(s2!=0 && s2%2==0) ++res;
            }
        }
    }

    cout << res << endl;

    return 0;
}
