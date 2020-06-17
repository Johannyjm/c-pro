#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    rep(i, m){
        cin >> p[i];
        --p[i];
    }

    vector<ll> a(n-1), b(n-1), c(n-1);
    rep(i, n-1) cin >> a[i] >> b[i] >> c[i];

    vector<int> imos(n-1, 0);
    rep1(i, m){
        int from = p[i-1];
        int to = p[i];
        if(from > to) swap(from, to);

        ++imos[from];
        --imos[to];
    }

    rep1(i, n){
        imos[i] += imos[i-1];
    }

    ll res = 0;
    rep(i, n-1){
        ll ticket = a[i] * imos[i];
        ll ic = b[i] * imos[i] + c[i];

        res += min(ticket, ic);        
    }

    cout << res << endl;


    return 0;
}