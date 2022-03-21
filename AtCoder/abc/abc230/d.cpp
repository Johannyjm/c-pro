#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, d;
    cin >> n >> d;

    vector<ll> l(n), r(n);
    vector<pair<ll, int>> ri(n);
    rep(i, n){
        cin >> l[i] >> r[i];

        r[i] += d-1;
        ri[i] = {r[i], i};
    }

    sort(ri.begin(), ri.end());

    int res = 1;
    int now = ri[0].first;
    rep1(i, n){
        if(l[ri[i].second] > now){
            now = ri[i].first;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}