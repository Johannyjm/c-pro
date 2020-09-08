#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    map<ll, ll> mp;
    rep(i, n){
        ll a;
        cin >> a;
        ++mp[a];
    }

    rep(i, m){
        ll b, c;
        cin >> b >> c;
        mp[c] += b;
    }

    ll res = 0;
    ll cnt = 0;
    for(auto itr = mp.rbegin(); itr != mp.rend(); ++itr){
        ll key = itr->first;
        ll val = itr->second;

        if(cnt+val <= n){
            res += key * val;
            cnt += val;

            if(cnt == n) break;
        }
        else{
            res += key * (n-cnt);
            break;
        }
    }

    cout << res << endl;




    

    return 0;
}