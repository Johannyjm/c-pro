#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> ab(n);
    ll res = 0;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        ab[i] = a+b;
        res -= b;
    }

    sort(ab.begin(), ab.end(), greater<ll>());
    rep(i, n){
        if(i%2 == 0) res += ab[i];
    }

    cout << res << endl;

    return 0;
}