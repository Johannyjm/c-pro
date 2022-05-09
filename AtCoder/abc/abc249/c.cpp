#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int res = 0;
    rep(i, 1<<n){
        vector<bool> use(n, false);
        int use_cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                use[j] = true;
                ++use_cnt;
            }
        }

        unordered_map<char, int> count;
        rep(j, n){
            if(!use[j]) continue;

            for(auto c: s[j]) ++count[c];
        }

        int sm = 0;
        for(auto key: count){
            if(key.second == k) ++sm;
        }
        res = max(res, sm);
    }

    cout << res << endl;

    return 0;
}