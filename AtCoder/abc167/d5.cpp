#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> d(61, vector<int>(n));
    rep(i, n) d[0][i] = a[i];
    rep1(i, 61){
        rep(j, n) d[i][j] = a[d[i-1][j]-1];
    }

    // rep(i, n){
    //     rep(j, n) cout << d[i][j] << " ";
    //     cout << endl;
    // }

    ll base = 1;
    while((1LL<<base) < k){
        ++base;
    }
    --base;

    int prev = 0;
    int curr;
    while(k){
        curr = d[base][prev];
        k -= 1LL << base;
        // cout << k << " " << curr << " " << endl;

        base = 1;
        while((1LL<<base) < k){
            ++base;
        }
        --base;

        prev = curr;
    }

    cout << d[0][curr] << endl;

    return 0;
}