#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll res = 0;
    ll now = 0;
    ll ptra = 0;
    ll ptrb = 0;
    bool endflga = false;
    bool endflgb = false;
    const ll INF = 1ll << 60;
    while(1){
        if(now > k) break;
        ll ta = INF;
        ll tb = INF;
        if(!endflga) ta = a[ptra];
        if(!endflgb) tb = b[ptrb];

        if(ta == tb){
            int tmpa = ptra;
            int tmpb = ptrb;
                
            if(tmpa == n-1){
                ++ta;
            }
            else if(tmpb == n-1){
                ++tb;
            }
            else{
                while(1){
                    ++tmpa;
                    ++tmpb;
                    if(tmpa==n && tmpb==m){
                        ++ta;
                        break;
                    }
                    if(tmpa==n && tmpb!=m){
                        ++ta;
                        break;
                    }
                    if(tmpa!=n && tmpb==m){
                        ++tb;
                        break;
                    }

                    if(a[tmpa] > b[tmpb]){
                        ++ta;
                        break;
                    }

                    if(a[tmpa] < b[tmpb]){
                        ++tb;
                        break;
                    }
                }
            }
        }

        if(ta < tb){
            
            now += ta;
            if(now > k){
                cout << res << endl;
                return 0;
            }
            ++res;
            ++ptra;
            if(ptra == n){
                endflga = true;
            }
        }

        else{
            
            now += tb;
            if(now > k){
                cout << res << endl;
                return 0;
            }
            ++res;
            ++ptrb;
            if(ptrb == m){
                endflgb = true;
            }
        }
        if(endflga && endflgb) break;

    }

    cout << res << endl;



    return 0;
}