#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> b(m), c(m);
    vector<vector<int>> idles(m);
    rep(i, m){
        cin >> b[i] >> c[i];
        vector<int> idle(c[i]);
        rep(j, c[i]) cin >> idle[j];

        idles[i] = idle;
    }

    int res = 0;
    rep(i, (1ll<<n)){
        vector<int> use(n, 0);
        int cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                use[j] = 1;
                ++cnt;
            }
        }

        if(cnt != 9) continue;
        
        int base = 0;
        rep(j, n) base += a[j] * use[j];

        int bonus = 0;
        rep(j, m){
            int b_cnt = 0;
            rep(k, c[j]){
                if(use[idles[j][k]-1] == 1){
                    ++b_cnt;
                }
            }

            if(b_cnt >= 3) bonus += b[j];
        }

        // if(base+bonus > res){
        //     rep(j, n) cout << use[j]<< " ";
        //     cout << endl;
        //     cout << base+bonus << endl;
        // }
        res = max(res, base+bonus);
    }

    cout << res << endl;

    return 0;
}