#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> h(2000), w(2000), smh(2000), smw(2000);
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0) break;
        h.clear();
        w.clear();
        smh.clear();
        smw.clear();
        rep(i, n) cin >> h[i];
        rep(i, m) cin >> w[i];

        smh[0] = 0;
        rep(i, n) smh[i+1] = h[i] + smh[i];
        smw[0] = 0;
        rep(i, m) smw[i+1] = w[i] + smw[i];

        map<int, int> cnth;
        for(int l = 0; l < n; ++l){
            for(int r = l+1; r < n+1; ++r){
                ++cnth[smh[r] - smh[l]];
            }
        }

        int res = 0;
        for(int l = 0; l < m; ++l){
            for(int r = l+1; r < m+1; ++r){
                res += cnth[smw[r] - smw[l]];
            }
        }

        cout << res << endl;
        

    }

    return 0;
}