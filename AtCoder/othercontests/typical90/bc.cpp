#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, p, q;
    cin >> n >> p >> q;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            for(int k = j+1; k < n; ++k){
                for(int l = k+1; l < n; ++l){
                    for(int m = l+1; m < n; ++m){
                        //if(!(i<j && j<k && k<l && l<m)) continue;
                        ll prod = 1;
                        prod = (prod * a[i]) % p;
                        prod = (prod * a[j]) % p;
                        prod = (prod * a[k]) % p;
                        prod = (prod * a[l]) % p;
                        prod = (prod * a[m]) % p;

                        if(prod == q) ++res;

                    }
                }
            }
        }
    }

    cout << res << endl;
    
    return 0;
}
