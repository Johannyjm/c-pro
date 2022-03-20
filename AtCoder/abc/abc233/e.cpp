#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    cin >> x;

    int n = x.size();
    vector<ll> a(n);
    rep(i, n){
        a[i] = x[i] - '0';
    }

    vector<ll> s(n);
    s[0] = a[0];
    rep1(i, n){
        s[i] = s[i-1] + a[i];
    }

    reverse(s.begin(), s.end());

    ll c = 0;
    vector<int> res;
    rep(i, n){
        ll sm = c + s[i];
        res.push_back(sm % 10);
        c = sm / 10;
    }

    if(c) res.push_back(c);

    reverse(res.begin(), res.end());

    for(auto e: res) cout << e;
    cout << endl;


    return 0;
}