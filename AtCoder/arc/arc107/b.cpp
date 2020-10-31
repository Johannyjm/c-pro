#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    set<pair<ll, ll>> st;
    for(ll x = 2; x <= 2*n; ++x){
        ll y = x - k;
        if(2<=y && y<=2*n){
            st.insert({x, y});
        }
    }

    ll res = 0;
    for(pair<ll, ll> e: st){
        ll x = e.first;
        ll y = e.second;
        ll xsm = 0;
        ll ysm = 0;

        if(n>=(x+1)/2){

            if(x==2){
                xsm = 1;
            }
            else if(x%2==0){
                xsm += min(x-1, (n-x/2) * 2 + 1);
            }
            else{
                xsm += min(x-1, ((n-(x+1)/2)+1) * 2);
            }
        }
        
        if(n>=(y+1)/2){
            if(y==2){
                ysm = 1;
            }
            else if(y%2==0){
                ysm += min(y-1, (n-y/2) * 2 + 1);
            }
            else{
                ysm += min(y-1, ((n-(y+1)/2)+1) * 2);
            }
        }

        // cout << x << " " << y << " " << xsm << " " << ysm << endl;
        
        res += xsm*ysm;
        // cout << res << endl;
    }

    cout << res << endl;



    return 0;
}