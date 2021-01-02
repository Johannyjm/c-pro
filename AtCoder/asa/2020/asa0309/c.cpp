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
    string s;
    cin >> n >> s;

    vector<ll> freq(26, 0);
    rep(i, n) ++freq[s[i]-'a'];
    const ll MOD = 1000000007;

    ll res = 1LL;
    rep(i, 26){
        res = (res%MOD*(freq[i]+1)%MOD)%MOD;
    }

    cout << res-1 << endl;


    return 0;
}