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

        // while(a[i]%b[i]){
        //     ++a[i];
        //     ++res;
        //     ++cnt;
        // }

        ll tmp = b[i] - a[i]%b[i];
        a[i] += tmp;
        cnt += tmp;
        res += tmp;
    }

    cout << res << endl;

    return 0;
}