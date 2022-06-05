#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll n;

ll count(ll num){
    ll sq = num*num;
    if(sq == 1) return 1;

    ll ret = 1;
    for(ll i = num-1; i >= 1; --i){
        if(sq%i == 0 && sq/i <= n) ret += 2;
        if(sq/i > n) break;
    }
    
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // cout << count(4) << " " << count(9) << " " << count(16) << endl;
    cin >> n;

    ll res = 0;
    for(ll i = 1; i <= n; ++i){
        res += count(i);

        // cout << i << " " << sq << " " << count(sq) << endl;

        // if(i*i > n) break;
    }

    cout << res << endl;

    return 0;
}