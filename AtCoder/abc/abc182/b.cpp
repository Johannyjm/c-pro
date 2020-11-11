#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = -1;
    int mx = 0;
    for(int i = 2; i <= 1000; ++i){
        int sm = 0;
        rep(j, n){
            if(a[j] % i == 0) ++sm;
        }
        if(sm > mx){
            res = i;
            mx = sm;
        }
    }

    cout << res << endl;

    return 0;
}