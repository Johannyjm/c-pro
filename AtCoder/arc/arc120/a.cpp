#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> mx(n, 0);
    vector<ll> sm(n, 0);
    vector<ll> mxsm(n, 0);
    rep(i, n){
        cin >> a[i];
        if(i==0){
            mx[i] = a[i];
            sm[i] = a[i];
            mxsm[i] = a[i];
            mxmx[i] = a[i];
        }
        else{
            mx[i] = max(mx[i-1], a[i]);
            sm[i] = sm[i-1] + a[i];
            mxmx[i] = max(mxmx[i], )
            mxsm[i] = mxsm[i-1] + mx[i-1];
        }
    }

    rep(i, n){
        cout << sm[i] + mxsm[i] << endl;
    }




    return 0;
}