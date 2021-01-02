#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int now = 0;
    int res = 0;
    int idx;
    rep(i, n){
        // A to B
        idx = lower_bound(a.begin(), a.end(), now) - a.begin();
        if(idx == n) break;
        now = a[idx] + x;

        // B to A
        idx = lower_bound(b.begin(), b.end(), now) - b.begin();
        if(idx == m) break;
        now = b[idx] + y;

        ++res;
    }

    cout << res << endl;    

    return 0;
}