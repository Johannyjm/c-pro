#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<pair<ll, int>> ai(n);
    rep(i, n){
        cin >> a[i];
        ai[i] = {a[i], i};
    }

    sort(ai.begin(), ai.end());

    // for(auto e: ai) cout << e.first << " " << e.second << endl;

    ll base = k / n;
    ll rest = k % n;
    vector<ll> res(n, base);
    rep(i, rest){
        ++res[ai[i].second];
    }

    for(auto e: res) cout << e << "\n";

    return 0;
}