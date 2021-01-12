#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, C;
    cin >> n >> C;

    vector<pair<ll, ll>> event;
    rep(i, n){
        ll a, b, c;
        cin >> a >> b >> c;

        event.push_back({a, c});
        event.push_back({b+1, -c});
    }

    sort(event.begin(), event.end());

    ll prev = 0;
    ll total = 0;
    ll res = 0;
    for(auto p: event){
        ll day = p.first;
        ll dif = p.second;

        res += (day - prev) * min(total, C);
        prev = day;
        total += dif;
    }

    cout << res << endl;

    return 0;
}