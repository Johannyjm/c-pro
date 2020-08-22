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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;
    ll prev = a[0];
    rep1(i, n){
        if(a[i] < prev){
            res += prev-a[i];
        }
        else prev = a[i];
    }

    cout << res << endl;

    return 0;
}