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

    ll now = 0;
    for(int i = 1; i*i <= 10 *n; ++i){
        now += i;
        
        if(now >= n){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}