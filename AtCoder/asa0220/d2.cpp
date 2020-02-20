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

    vector<ll> s(n+1);
    s[0] = 0;
    rep1(i, n+1){
        ll a;
        cin >> a;
        s[i] = s[i-1] + a;
    }

    sort(s.begin(), s.end());

    map<ll, ll> num;
    rep(i, n+1){
        ++num[s[i]];
    }

    // rep(i, n+1) cout << s[i] << " ";
    // cout << endl;

    ll res = 0;
    for(auto iter = num.begin(); iter != num.end(); ++iter){
        ll m = iter->second;
        res += (m==2)? 1: (m-1) * (m-2);
    }

    cout << res << endl;


    return 0;
}