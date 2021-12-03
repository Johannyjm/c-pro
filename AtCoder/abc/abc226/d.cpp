#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}

pair<ll, ll> calcgrad(ll ai, ll bi, ll aj, ll bj){
    ll top = bj - bi;
    ll bottom = aj - ai;

    ll g = gcd(top, bottom);

    return {top/g, bottom/g};

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    set<pair<ll, ll>> st;
    rep(i, n) rep(j, n){
        if(i == j) continue;

        pair<ll, ll> grad = calcgrad(a[i], b[i], a[j], b[j]);
        st.insert(grad);
    }

    cout << st.size() * 2 << endl;

    return 0;
}