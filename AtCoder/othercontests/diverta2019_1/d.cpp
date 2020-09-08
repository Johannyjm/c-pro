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

    ll res = 0;
    for(ll i = 1; i*i <= n; ++i){
        if((n-i) % i == 0 && ((n-i)/i != 0 && (n/((n-i)/i) == (n%((n-i)/i))))){
            res += (n-i)/i;
        }
    }

    cout << res << endl;

    return 0;
}