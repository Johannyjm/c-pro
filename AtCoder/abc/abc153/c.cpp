#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    sort(h.begin(), h.end(), greater<int>());

    ll res = 0;

    rep(i, n){
        if(i<k) continue;
        res += h[i];
    }

    cout << res << endl;
    
    return 0;
}