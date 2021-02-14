#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll l, r;
        cin >> l >> r;
        
        if(l*2 > r){
            cout << 0 << endl;
            continue;
        }

        ll n = r - l*2 + 1;
        cout << n * (n+1) / 2 << endl;
    }

    return 0;
}