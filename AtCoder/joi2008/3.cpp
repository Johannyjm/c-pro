#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    p[0] = 0;
    rep(i, n) cin >> p[i+1];
    ll min_d = n;
    ll res = 0;

    rep(a, n+1){
        if(p[a] > m) continue;
        rep(b, n+1){
            if(p[a]+p[b] > m) continue;
            rep(c, n+1){
                if(p[a]+p[b]+p[c] > m) continue;
                rep(d, n+1){
                    if(p[a]+p[b]+p[c]+p[d] > m) continue;

                    int di = p[a]+p[b]+p[c]+p[d];
                    if(m-di < min_d){
                        res = di;
                        min_d = m-di;
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}