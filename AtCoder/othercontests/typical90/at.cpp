#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(46, 0), b(46, 0), c(46, 0);
    for(int i = 0; i < n; ++i){
        int a_;
        cin >> a_;
        ++a[a_ % 46];
    }
    for(int i = 0; i < n; ++i){
        int b_;
        cin >> b_;
        ++b[b_ % 46];
    }
    for(int i = 0; i < n; ++i){
        int c_;
        cin >> c_;
        ++c[c_ % 46];
    }

    ll res = 0;
    for(int i = 0; i < 46; ++i){
        for(int j = 0; j < 46; ++j){
            for(int k = 0; k < 46; ++k){
                if((i + j + k) % 46 != 0) continue;

                res += a[i] * b[j] * c[k];
            }
        }
    }

    cout << res << endl;

    return 0;
}
