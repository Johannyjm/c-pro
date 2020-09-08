#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int w = -1;
    int x = -1;
    int y = -1;
    int z = -1;

    if(a.front() < 0) w = 0;
    else y = 0;

    if(a.back() < 0) x = a.size()-1;
    else z = a.size()-1;
    rep1(i, n){
        if(a[i]*a[i-1] < 0){
            x = i-1;
            y = i;
            break;
        }
    }
    cout << w << x << y << z << endl;
    return 0;
    
    ll l = 0;
    ll r = a.size()-1;
    rep(i, k){

        if(a[l]*a[r] < 0){
            if(a[l+1]*a[r-1] < 0){
                if(abs(a[l+1])>abs(a[r-1])){
                    ++l;
                    r = a.size()-1;
                }
                else{
                    --r;
                    l = 0;
                }
            }
            else{
                if(a[l]*a[l+1] < 0){
                    --r;
                }
                if(a[r]*a[r-1] < 0){
                    ++l;
                }
            }
        }

        cout << l << " " << r << endl;
    }

    return 0;
}