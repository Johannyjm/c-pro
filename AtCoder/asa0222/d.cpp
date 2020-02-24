#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, tmp;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    bool flg = false;
    const ll MOD = 1000000007LL;

    rep(i, n){
        cin >> tmp;

        if(n%2){
            if(tmp%2){
                flg = true;
            }
            if(tmp==0 && mp[tmp]>0) flg = true;
            if(tmp!=0 && mp[tmp]>1) flg = true;
        }
        
        else{
            if(tmp%2){
                if(mp[tmp]>1) flg = true;
            }
            else flg = true;
        }

        if(flg){
            cout << 0 << endl;
            return 0;
        }

        ++mp[tmp];
    }

    if(n+tmp==0) cout << 1 << endl;
    else cout << ((n/2)%MOD * (n/2)%MOD) % MOD << endl;


    return 0;
}