#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> s(n-1);
    rep(i, n-1) cin >> s[i];

    vector<int> a(m);
    rep(i, m) cin >> a[i];

    vector<int> sm(n);
    sm[0] = 0;
    rep1(i, n){
        sm[i] = sm[i-1] + s[i-1];
    }


    int from = 0;
    int res = 0;
    const int mod = 100000;
    rep(i, m){
        int to = from + a[i];
        int dist = abs(sm[to] - sm[from]) % mod;
        
        res = (res + dist) % mod;
        from = to;
    }

    cout << res << endl;

    return 0;
}