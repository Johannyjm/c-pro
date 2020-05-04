#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    vector<vector<ll>> g(n);
    map<ll, ll> highest;
    rep(i, m){
        ll a, b;
        cin >> a >> b;

        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        
        highest[a] = max(highest[a], h[b]);
        highest[b] = max(highest[b], h[a]);
    }

    ll res = 0;
    rep(i, n){
        if(h[i] > highest[i]) ++res;
    }

    cout << res << endl;

    return 0;
}