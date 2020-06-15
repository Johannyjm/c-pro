#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            ret.insert(i);
            if(i*i != n) ret.insert(n/i);
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<set<ll>> divs(n);
    rep(i, n){
        divs[i] = divisor(a[i]);
    } 

    map<int, int> mp;
    rep(i, n) ++mp[a[i]];

    int res = 0;
    rep(i, n){
        set<ll> st = divs[i];
        bool flg = true;
        for(auto ele: st){
            if(ele == a[i]){
                if(mp[ele] != 1){
                    flg = false;
                    break;
                }
            }

            else if(mp[ele] > 0){
                flg = false;
                break;
            }
        }

        if(flg) ++res;
    }

    cout << res << endl;


    return 0;
}