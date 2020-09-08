#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;
    ll subsum = 0;
    rep(i, n){
        if(a[i]) subsum += a[i];
        else{
            res += subsum/2;
            subsum = 0;
        }
    }
    if(subsum) res += subsum/2;

    cout << res << endl;

    return 0;
}