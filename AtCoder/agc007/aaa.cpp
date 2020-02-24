#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k, a[100010];
    ll ans = 0;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll s[100010] = {0};
    s[0] = a[0];
    rep1(i, n){
        s[i] = s[i-1] + a[i];
    }
    ans += s[k-1];
    for(int i = 0; i+k < n; ++i){
        ans += s[i+k] - s[i];
    }
    cout << ans << endl;

    return 0;
}