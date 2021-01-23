#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    map<ll, ll> cnt;
    rep(i, n){
        cin >> v[i];
        ++cnt[v[i]];
    }

    sort(v.begin(), v.end(), greater<ll>());

    double res1 = 0.0;
    rep(i, a) res1 += (double)v[i] / a;

    cout << setprecision(20);
    cout << res1 << endl;

    return 0;
}