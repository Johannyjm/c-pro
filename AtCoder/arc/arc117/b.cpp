#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    
    set<ll> uni;
    for(auto e: A) uni.insert(e);

    vector<ll> a;
    for(auto e: uni) a.push_back(e);
    a.push_back(0);

    sort(a.begin(), a.end(), greater<ll>());

    n = a.size();

    // for(auto e: a) cout << e << " ";
    // cout << endl;

    vector<mint> diff(n-1);
    rep(i, n-1){
        diff[i] = a[i] - a[i+1];
    }

    // for(auto e: diff) cout << e.val() << " ";
    // cout << endl;

    mint res = 1;
    mint buf = 0;
    for(auto e: diff){
        buf = res*e;
        res += buf;
    }

    cout << res.val() << endl;

    return 0;
}