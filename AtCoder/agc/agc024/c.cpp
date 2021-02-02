#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll res = 0;
    ll prev = 0;
    rep(i, n){
        ll now;
        cin >> now;
        if(now > i){
            cout << -1 << endl;
            return 0;
        }

        if(now == prev+1) ++res;
        else if(now <= prev) res += now;
        else{
            cout << -1 << endl;
            return 0;
        }
        
        prev = now;
    }

    cout << res << endl;

    return 0;
}