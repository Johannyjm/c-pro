#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, w;
    cin >> n >> w;

    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;

    sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());

    ll res = 0;
    ll now = 0;
    rep(i, n){
        if(now + ab[i].second <= w){
            res += ab[i].first * ab[i].second;
            now += ab[i].second;
        }
        else{
            res += ab[i].first * (w - now);
            break;
        }
    }

    cout << res << endl;


    return 0;
}