#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1, 0), b(m+1, 0);
    rep(i, n) cin >> a[i+1];
    rep(i, n) a[i+1] += a[i];
    rep(i, m) cin >> b[i+1];
    rep(i, m) b[i+1] += b[i];

    int b_cnt = m;
    int res = 0;
    rep(a_cnt, n+1){
        while(a[a_cnt] + b[b_cnt] > k) --b_cnt;
        res = max(res, a_cnt+b_cnt);
    }

    cout << res << endl;

    return 0;
}