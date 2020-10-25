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
    const int mod = 1000000007;

    ll res = 1;
    rep(i, n){
        res = (res*(i+1)) % mod;
    }

    cout << res << endl;

    return 0;
}