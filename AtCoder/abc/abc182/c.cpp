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
    rep(i, (1<<n)){
        vector<int> drop(n);
        int cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                drop[j] = 1;
                ++cnt;
            }
        }

        if(cnt > res) continue;

        int sm = 0;
        // ll base = 1;
        rep(j, n){
            if(drop[j] == 1) continue;
            sm += s[j] - '0';
        }

        if(sm % 3 == 0) res = min(cnt, res);

    }

    if(res >= n) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}