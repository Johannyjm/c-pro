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
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector<vector<vector<ll>>> cnt(n*n, vector<vector<ll>>(n, vector<ll>(n, 0)));
    rep(fi, n) rep(fj, n) rep(ti, n) rep(tj, n){
        
        bool flg = true;
        if(fi == ti){
            rep(i, n){
                if(a[i][fj] + a[i][tj] > k){
                    flg = false;
                    break;
                }
            }
        }
        
        if(fj == tj){
            rep(j, n){
                if(a[fi][j] + a[ti][j] > k){
                    flg = false;
                    break;
                }
            }
        }

        if(fi == ti && fj == tj) flg = true;

        if(flg) ++cnt[fi*fj][ti][tj];
    }


    ll res = 0;
    ll mod = 998244353;
    rep(i, n) rep(j, n){
        res = (res * cnt[i][j]) % mod;
    }

    return 0;
}