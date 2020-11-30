#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, z, w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if(n==1){
        cout << abs(a[0]-w) << endl;
        return 0;
    }

    ll res = max(abs(a[n-2]-a[n-1]), abs(a[n-1]-w));

    cout << res << endl;

    return 0;
}