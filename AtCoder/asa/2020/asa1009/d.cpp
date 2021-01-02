#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    for(ll a = 1; a <= 3500; ++a) for(ll b = 1; b <= 3500; ++b){
        ll l = n*a*b;
        ll rl = 4*a*b - n*(a+b);
        if(rl <= 0) continue;
        if(l%rl == 0){
            // cout << l << " " << rl << endl;
            cout << a << " " << b << " " << l/rl << endl;
            return 0;
        }
    }

    return 0;
}