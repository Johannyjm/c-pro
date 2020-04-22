#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll res = 0;
    ll curr = 0;
    for(int i = n-1; i >= 0; --i){
        if((a[i]+ curr)%b[i] == 0) continue;
        res += b[i] - (a[i] + curr) % b[i];
        curr += b[i] - (a[i] + curr) % b[i];
    }

    cout << res << endl;

    return 0;
}