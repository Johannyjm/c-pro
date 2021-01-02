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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<vector<int>> bit(n, vector<int>(60, 0));
    rep(i, n){
        ll num = a[i];
        int base = 0;
        while(num){
            bit[i][base] = num%2;
            num/=2;
            ++base;
        }
        reverse(bit[i].begin(), bit[i].end());
    }

    rep(i, n){
        rep(j, 60) cout << bit[i][j] << " ";
        cout << endl;
    }

    int base = 0;
    vector<int> kbit(60, 0);
    while(k){
        kbit[base] = k%2;
        k/=2;
        ++base;
    }
    reverse(kbit.begin(), kbit.end());
    rep(i, 60) cout << kbit[i] << " ";
    cout << endl;
    cout << base << endl;

    ll dp[base+1][2] = {};
    dp[0][0]
    rep(i, base){
        rep(j, 2){
            dp[i+1] += 
        }
    }


    return 0;
}