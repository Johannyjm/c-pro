#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    const ll m = 10000;
    ll res = 1001001001;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            ll rest = n - (a*i + b*j);
            if(rest < 0) continue;

            if(rest % c == 0){
                res = min(res, i + j + rest/c);
            }
        }
    }

    cout << res << endl;

    return 0;
}
