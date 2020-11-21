#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int res = n+1;
    rep(i, 1<<n){
        vector<int> drop(n, 0);
        int drpcnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                drop[j] = 1;
                ++drpcnt;
            }
        }

        if(drpcnt > res) continue;

        int sm = 0;
        rep(j, n){
            if(drop[j]) continue;
            sm += s[j] - '0';
        }
        // cout << sm << " " << drpcnt << endl;

        if(sm % 3 == 0) res = min(res, drpcnt);
    }

    if(res == n) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}