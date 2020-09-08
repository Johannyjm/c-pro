#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> c(4);
    rep(i, 4) cin >> c[i];
    ll n;
    cin >> n;
    ll min_c = min(c[0]*8, min(c[1]*4, min(c[2]*2, c[3])));

    cout << (n/2)*min_c + (n%2!=0) * min(c[0]*4, min(c[1]*2, c[2])) << endl;



    return 0;
}