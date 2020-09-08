#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n){
        ll tm;
        cin >> tm;
        --tm;
        a[i] = tm;
    }

    ll T = 1;
    ll curr = a[0];
    ll nxt;
    vector<ll> lam;
    lam.push_back(0);
    lam.push_back(curr);
    while(curr != 0){
        nxt = a[curr];
        
        if(nxt != 0) lam.push_back(nxt);
        curr = nxt;

        ++T;
    }

    cout << T << endl;
    rep(i, lam.size()) cout << lam[i] << " ";
    cout << endl;

    cout << a[lam[k%T-1]] + 1 << endl;

    return 0;
}