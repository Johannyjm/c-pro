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
    map<ll, ll> d_map;
    rep(i, n) {
        ll d;
        cin >> d;
        ++d_map[d];
    }

    ll m;
    cin >> m;
    rep(i, m){
        ll t;
        cin >> t;

        if(d_map[t]) --d_map[t];
        else {
            puts("NO");
            return 0;
        }
    }

    puts("YES");



    return 0;
}