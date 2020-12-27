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

    int t;
    cin >> t;

    while(t--){
        ll n, s, k;
        cin >> n >> s >> k;

        pair<ll, ll> c = crt({0, s}, {n, k});

        if(c == make_pair(0ll, 0ll)){
            cout << -1 << endl;
            continue;
        }

        ll cr = c.first%c.second;
        if(cr < s) cr = c.first + c.second;

        cout << (cr-s)/k << endl;
    }

    return 0;
}