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

    int minus = 0;
    int zero = 0;
    int plus = 0;
    rep(i, n){
        if(a[i]<0) ++minus;
        if(a[i]==0) ++zero;
        if(a[i]>0) ++plus;
    }

    if(minus>0 && plus>0){
        if(plus*minus>k){
            int l = (k-1)/plus;
            int r = n - 1 - (k-1)%plus;
            cout << a[l] * a[r] << endl;
            return 0;
        }
        else{
            if(k - plus*minus <= zero*(n-1)){
                cout << 0 << endl;
                return 0;
            }
            k = k - plus*minus - zero*(n-1);
            rep(i, k){
                
            }
        }
    }


    return 0;
}