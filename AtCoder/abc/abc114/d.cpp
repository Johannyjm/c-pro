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

ll nCk(ll n, ll k){
    k = min(k, n-k);
    ll ret = 1;
    for(ll i = 0; i < k; ++i){
        ret *= n-i;
        ret /= i+1;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if(n <= 9){
        cout << 0 << endl;
        return 0;
    }

    map<ll, ll> primes;
    for(ll i = 2; i <= n; ++i){
        pair<map<ll, ll>, set<ll>> out = prime_factor(i);
        
        for(auto k: out.first){
            primes[k.first] += k.second;
        }
    }

    vector<ll> ex;
    for(auto k: primes){
        ex.push_back(k.second);
    }

    // for(auto k: primes){
    //     cout << k.first << ":" << k.second << " ";
    // }
    // cout << endl;

    sort(ex.begin(), ex.end(), greater<ll>());

    // ll cnt74 = 0;
    // ll cnt24 = 0;
    // ll cnt14 = 0;
    // ll cnt4 = 0;
    // ll cnt2 = 0;
    // for(auto e: ex){
    //     if(e >= 74) ++cnt74;
    //     if(e >= 24) ++cnt24;
    //     if(e >= 14) ++cnt14;
    //     if(e >= 4) ++cnt4;
    //     if(e >= 2) ++cnt2;
    // }
    
    // ll res = cnt74;
    
    // if(cnt24 <= 1) res += cnt24 * (cnt2-1);
    // else res += nCk(cnt24, 2) + cnt24*(cnt2-cnt24);
    
    // if(cnt14 <= 1) res += cnt14 * (cnt4-1);
    // else res += nCk(cnt14, 2) + cnt14*(cnt2-cnt14);
    
    // if(cnt4 <= 2) res += cnt2-cnt4;
    // else res += nCk(cnt4, 3) + nCk(cnt4, 2)*(cnt2-cnt4);
    int m = ex.size();

    ll res = 0;
    rep(i, m){
        if(ex[i] >= 74) ++res;
    }

    for(int i = 0; i < m-1; ++i){
        for(int j = i+1; j < m; ++j){
            // if(ex[i]>=24 && ex[j]>=2) ++res;
            // if(ex[i]>=24 && ex[j]>=24) ++res;
            // if(ex[i]>=14 && ex[j]>=4) ++res;
            // if(ex[i]>=14 && ex[j]>=14) ++res;
            rep1(k, ex[i]+1) rep1(l, ex[j]+1){
                if((k+1)*(l+1) == 75) ++res;
            }
        }
    }

    rep(i, m) rep(j, m) rep(k, m){
        // int c2 = 0;
        // int c4 = 0;
        // if(ex[i]>=4) ++c4;
        // else if(ex[i]>=2) ++c2;
        // if(ex[j]>=4) ++c4;
        // else if(ex[j]>=2) ++c2;
        // if(ex[k]>=4) ++c4;
        // else if(ex[k]>=2) ++c2;
        
        // if((c4>=2 && c2>=1) || c4>=3){
        //     cout << ex[i] << " " << ex[j] << " " << ex[k] << endl;
        //     ++res;
        // }
        if(!(i<j && j<k)) continue;
        // if((ex[i]>=4 && ex[j]>=4 && ex[k]>=4)
        // || (ex[i]>=4 && ex[j]>=4 && ex[k]>=2)
        // || (ex[i]>=4 && ex[j]>=2 && ex[k]>=4)
        // || (ex[i]>=2 && ex[j]>=4 && ex[k]>=4)) ++res;
        rep1(ii, ex[i]+1) rep1(jj, ex[j]+1) rep1(kk, ex[k]+1){
            if((ii+1)*(jj+1)*(kk+1) == 75){
                ++res;
            }
        }
    }

    cout << res << endl;

    return 0;
}