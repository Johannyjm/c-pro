#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x, y, z;
    cin >> x >> y >> z;

    for(ll w = 1000000; w >= 0; --w){
        if(x*w < z*y){
            cout << w << endl;
            return 0;
        }
    }

    return 0;
}