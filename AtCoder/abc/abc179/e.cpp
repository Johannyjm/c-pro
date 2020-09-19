#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x, m;
    cin >> n >> x >> m;

    if(n == 1){
        cout << x << endl;
        return 0;
    }

    vector<ll> mods(m, 0);
    mods[x] = 1;
    ll res = x;
    ll prev = x;
    ll start = -1;
    ll end = -1;
    vector<ll> a;
    a.push_back(x);
    for(int i = 1; i < n; ++i){
        ll curr = prev*prev%m;
        if(start == -1 && mods[curr] == 1){
            start = i;
        }
        if(start != -1 && mods[curr] == 2){
            end = i;
            break;
        }
        res += curr;
        a.push_back(curr);
        if(i == n-1){
            cout << res << endl;
            return 0;
        }
        ++mods[curr];
        prev = curr;
    }

    // cout << start << " " << end << endl;
    // // for(int i = 0; i < a.size(); ++i) cout << a[i] << " ";
    // cout << endl;

    ll ans = 0;
    for(int i = 0; i < start; ++i) ans += a[i];
    ll loop = 0;
    for(int i = start; i < end; ++i) loop += a[i];
    ll l = end-start;
    ll t = (n-start) / l;
    ans += loop * t;

    ll r = (n-start) % l;
    // cout << r <s< endl;
    for(int i = start%l; i <= r+1; ++i) {
        ans += a[i];
        // cout s<< i << " " << ans << endl;
    }



    cout << ans << endl;
    return 0;
}