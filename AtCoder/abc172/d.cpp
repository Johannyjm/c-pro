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

    vector<ll> p(n+1, 2);
    p[0] = 0;
    p[1] = 1;
    for(int i = 2; i < n+1; ++i){
        for(int j = 2*i; j < n+1; j += i){
            ++p[j];
        }
    }

    ll res = 0;
    rep1(i, n+1) res += i*p[i];

    cout << res << endl;

    return 0;
}