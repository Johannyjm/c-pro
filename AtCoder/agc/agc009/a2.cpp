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

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll res = 0;
    ll cnt = 0;
    for(int i = n-1; i >=0; --i){
        a[i] += cnt;
        if(b[i] == 1 || a[i]%b[i]==0) continue;

        ll inc_tmp = b[i] - a[i]%b[i];
        a[i] += inc_tmp;
        cnt += inc_tmp;
        res += inc_tmp;
    }

    cout << res << endl;

    return 0;
}