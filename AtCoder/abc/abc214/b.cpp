#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll s, t;
    cin >> s >> t;

    ll res = 0;
    for(ll i = 0; i <= s; ++i){
        for(ll j = 0; j <= s; ++j){
            for(ll k = 0; k <= s; ++k){
                if(i+j+k > s) continue;
                if(i*j*k > t) continue;
                ++res;
            }
        }
    }

    cout << res << endl;

    return 0;
}