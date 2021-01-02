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
    vector<ll> a;
    a.push_back(0);
    rep(i, n){
        ll a_;
        cin >> a_;
        a.push_back(a_);
    }

    sort(a.begin(), a.end());
    vector<ll> sm(n+1, 0);
    sm[1] = a[1];
    int res = 1;
    for(int i = 2; i < n+1; ++i){
        if(sm[i-1]*2 >= a[i]) ++res;
        else res = 1;

        sm[i] = sm[i-1] + a[i];
    }

    cout << res << endl;

    return 0;
}