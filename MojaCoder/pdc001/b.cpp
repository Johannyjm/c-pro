#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

pair<map<ll, ll>, set<ll>> prime_factor(ll n){
    map<ll, ll> res;
    set<ll> primes;
    for(ll i = 2; i*i <= n; ++i) {
        if(n%i==0) primes.insert(i);

        while(n%i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
        primes.insert(n);
    }
    return make_pair(res, primes);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    unordered_set<ll> st;
    unordered_map<ll, ll> mp;
    rep(i, n){
        if(i == 0){
            ll tmp = a[0];
            for(ll i = 2; i*i <= tmp; ++i) {
                if(tmp%i==0) st.insert(i);

                while(tmp%i == 0){
                    ++mp[i];
                    tmp /= i;
                }
            }
            if(tmp != 1) {
                mp[tmp] = 1;
                st.insert(tmp);
            }
            continue;
        }

        unordered_set<ll> newst;
        unordered_map<ll, ll> newmp;
        ll tmp = a[i];
        for(auto i: st){
            if(tmp%i == 0) newst.insert(i);

            while(tmp%i == 0){
                ++newmp[i];
                tmp /= i;
            }
        }
        if(tmp != 1){
            newmp[tmp] = 1;
            newst.insert(tmp);
        }

        st = newst;

        for(auto k: mp){
            mp[k.first] = min(mp[k.first], newmp[k.first]);
        }
    }

    ll res = 1;
    for(auto k: mp){
        res *= k.second + 1;
        // cout << k.first << " " << k.second << endl;
    }

    cout << res << endl;

    return 0;
}