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
    vector<ll> d(n+1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; j += i){
            ++d[j];
        }
    }
    d[1] = 1;
    d[2] = 2;

    ll res = 0;
    for(ll i = 1; i <= n; ++i){
        res += i * d[i];
    }

    cout << res << endl;

    return 0;
}