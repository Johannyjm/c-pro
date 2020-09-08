#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
 
    ll ans = 0;
    
    vector<ll> mods(2019, 0);

    ll cur = 0, coef = 1;
    mods[cur]++;
    rep(i, n) {
        cur = (cur + coef * (s[n - i - 1] - '0') % 2019) % 2019;
        coef = coef * 10 % 2019;
        mods[cur]++;
    }

    rep(i, 2019) {
        ans += mods[i] * (mods[i] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}