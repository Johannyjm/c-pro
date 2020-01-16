#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    map<ll, ll> mp;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll res = 0;
    rep1(i, 100001){
        res += mp[i];
        if(res >= k){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}