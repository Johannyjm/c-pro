#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    pair <ll, ll> ab[n];

    for (ll i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;

        ab[i] = make_pair(a, b);
    }
    sort(ab, ab+n);

    for(ll i = 0; i < n; ++i){
        cout << ab[i].first << " " << ab[i].second << endl;
    }
    ll res = 0;
    ll cnt = 0;

    for (ll i = 0; i < n; ++i){
        if(cnt + ab[i].second < m){
            res += ab[i].first * ab[i].second;
            cnt += ab[i].second;
        }
        else{
            res += ab[i].first * (m - cnt);
            cnt += m - cnt;
            break;
        }
    }
    cout << res << endl;
}