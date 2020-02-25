#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);

    ll subsum = 0;
    rep(i, n){
        cin >> a[i];
        if(i < k) subsum += a[i];
    }

    ll res = subsum;
    rep(i, n-k){
        subsum = subsum + a[k + i] - a[i];
        res += subsum;
    }

    cout << res << endl;

    return 0;
}