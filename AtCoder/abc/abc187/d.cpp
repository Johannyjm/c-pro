#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, pair<ll, ll>>> sab(n);
    ll aoki = 0;
    rep(i, n){
        cin >> a[i] >> b[i];
        sab[i] = {2*a[i]+b[i], {a[i], b[i]}};
        aoki += a[i];
    }

    sort(sab.begin(), sab.end(), greater<pair<ll, pair<ll, ll>>>());

    int res = 0;
    ll takahashi = 0;
    rep(i, n){
        if(takahashi > aoki) break;
        aoki -= sab[i].second.first;
        takahashi += sab[i].second.first + sab[i].second.second;
        // cout << aoki << " " << takahashi << endl;
        ++res;
    }

    cout << res << endl;

    return 0;
}