#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n != 0){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

ll lcm(ll m, ll n){
    return m/gcd(m, n)*n;
}

pair<ll, ll> yakubun(ll n, ll d){
    ll n0 = n;
    ll d0 = d;
    for(ll i = 2; i < max(n, d); ++i){
        while(n0%i==0 && d0%i == 0){
            n0 /= i;
            d0 /= i;
        }
        if(lcm(n0, d0) == n0*d0) break;
    }
    return make_pair(n0, d0);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n1, d1, n2, d2;
    string p;
    cin >> n1 >> d1 >> p >> n2 >> d2;

    if(p == "+"){
        ll d3 = d1*d2;
        ll n3 = d2*n1+d1*n2;
        pair<ll, ll> nd;
        nd = yakubun(n3, d3);
        n3 = nd.first;
        d3 = nd.second;

        if(d3 == 1)cout << n3 << endl;
        else cout << n3 << " " << d3 << endl;
        return 0;
    }
    if(p == "-"){
        ll d3 = d1*d2;
        ll n3 = d2*n1-d1*n2;
        pair<ll, ll> nd;
        nd = yakubun(n3, d3);
        n3 = nd.first;
        d3 = nd.second;

        if(d3 == 1)cout << n3 << endl;
        else cout << n3 << " " << d3 << endl;
        return 0;
    }
    if(p == "*"){
        ll d3 = d1*d2;
        ll n3 = n1*n2;
        pair<ll, ll> nd;
        nd = yakubun(n3, d3);
        n3 = nd.first;
        d3 = nd.second;

        if(d3 == 1)cout << n3 << endl;
        else cout << n3 << " " << d3 << endl;
        return 0;
    }
    if(p == "/"){
        ll d3 = d1*n2;
        ll n3 = d2*n1;
        pair<ll, ll> nd;
        nd = yakubun(n3, d3);
        n3 = nd.first;
        d3 = nd.second;

        if(d3 == 1)cout << n3 << endl;
        else cout << n3 << " " << d3 << endl;
        return 0;
    }
}