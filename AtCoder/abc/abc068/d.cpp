#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    if(k==1){
        cout << 3 << endl;
        cout << "1 0 3" << endl;
        return 0;
    }
    
    for(ll n = 50; n >= 2; --n){
        if((k+(n*(n-1))) % n == 0){
            ll i = (k+(n*(n-1))) / n;
            cout << n << endl;
            for(int _ = 0; _ < n-1; ++_) cout << i << " ";
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}