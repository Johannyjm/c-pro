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

    ll allxor = 0;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        allxor ^= a[i];
    }

    rep(i, n) cout << (a[i]^allxor) << " ";
    cout << endl;



    return 0;
}