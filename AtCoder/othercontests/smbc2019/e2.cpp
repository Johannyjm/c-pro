#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> cnt(3, vector<ll>(n, -1));
    ll res = 1;
    const ll mod = 1000000007;
    rep(i, n){
        ll c = 0;
        rep(j, 3){
            if(a[i]==0 && cnt[j][a[i]] == -1) ++c;
            if(a[i]!=0 && (cnt[j][a[i]]==-1 && cnt[j][a[i]-1]==1)) ++c;
        }
        rep(j, 3){
            if(cnt[j][a[i]] == -1){
                cnt[j][a[i]] = 1;
                break;
            }
        }
        res = res*c%mod;
    }

    cout << res << endl;

    return 0;
}