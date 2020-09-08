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

    ll res = 1;
    vector<ll> baby = {0, 1};
    rep(i, n){
        res += baby[i%2];
        baby[i%2] += baby[1-i%2];
    }

    cout << res << endl;
}