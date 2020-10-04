#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    ll n = 50;
    ll start = k / n;
    vector<ll> res(n);
    for(ll i = 0; i < n; ++i) res[i] = start + i;

    for(ll i = 0; i < k%n; ++i){
        ll min_val = 1ll<<60;
        int min_idx = -1;
        rep(i, n){
            if(res[i] < min_val){
                min_val = res[i];
                min_idx = i;
            }
        }
        rep(i, n){
            if(i == min_idx) res[i] += n;
            else res[i] -= 1ll;
        }
    }

    cout << n << endl;
    rep(i, n-1) cout << res[i] << " ";
    cout << res[n-1] << endl;

    return 0;
}