#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

pair<map<ll, ll>, set<ll>> prime_factor(ll n){
    map<ll, ll> res;
    set<ll> primes;
    for(ll i = 2; i*i <= n; ++i) {
        if(n%i==0) primes.insert(i);

        while(n%i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
        primes.insert(n);
    }
    return make_pair(res, primes);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    pair<map<ll, ll>, set<ll>> mpst = prime_factor(n);

    map<ll, ll> mp = mpst.first;
    set<ll> st = mpst.second;

    // cout << st.size() << endl;
    int res = 0;
    for(auto ele: st){
        // cout << ele << " " << mp[ele] << endl;
        int sm = 0;
        int nm = mp[ele];
        int cnt = 1;
        while(1){
            if(nm >= cnt){
                nm -= cnt;
                ++sm;
                ++cnt;
            }
            else break;
        }

        res += sm;
    }

    cout << res << endl;

    return 0;
}