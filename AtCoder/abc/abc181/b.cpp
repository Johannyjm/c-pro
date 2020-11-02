#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<ll> sm(1100000, 0);
    sm[1] = 1;
    rep1(i, 1010000){
        sm[i+1] = sm[i] + i+1;
    }

    // rep(i, 10) cout << sm[i] << " ";
    // cout << endl;

    ll res = 0;
    rep(i, n){
        ll a, b;
        cin >> a >> b;

        res += sm[b] - sm[a-1];

    }

    cout << res << endl;

    return 0;
}