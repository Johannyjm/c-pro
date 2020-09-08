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

    const int D = 60;
    const int MAX_N = 200005;
    vector<vector<int>> to(D, vector<int>(MAX_N)); // from j to 2<<i

    rep(i, n){
        cin >> to[0][i];
        --to[0][i];
    }

    rep(i, D-1){
        rep(j, n) to[i+1][j] = to[i][to[i][j]];
    }

    int v = 0;
    for(int i = D-1; i >= 0; --i){
        ll l = 1ll<<i;
        if(l <= k){
            v = to[i][v];
            k -= l;
        }
    }

    cout << v+1 << endl;

    return 0;
}