#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> cnt(n+1, 0);
    rep1(i, n+1){
        for(int j = i; j <= n; j += i){
            ++cnt[j];
        }
    }

    ll res = 0;
    rep1(i, n+1){
        res += i*cnt[i];
    }

    cout << res << endl;

    return 0;
}