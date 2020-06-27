#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k, m, r;
    cin >> n >> k >> m >> r;

    vector<ll> s(n-1);
    rep(i, n-1) cin >> s[i];

    sort(s.begin(), s.end(), greater<ll>());

    if(n == k){
        ll sm = 0;
        rep(i, n-1) sm += s[i];

        if(sm >= r*k) cout << 0 << endl;
        else{
            if(r*k - sm >= m) cout << r*k - sm << endl;
            else cout << -1 << endl;
        }

        return 0;
    }

    ll sm = 0;
    rep(i, k) sm += s[i];

    if(sm >= r*k) cout << 0 << endl;
    else{
        ll low = s[k-1];
        if(sm-low+m > r*k) cout << r*k - sm + low << endl;
        else cout << -1 << endl;
    }


    return 0;
}