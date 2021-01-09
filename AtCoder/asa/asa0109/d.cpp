#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> k(m);
    vector<vector<int>> s(m);
    vector<int> p(m);

    rep(i, m){
        cin >> k[i];
        rep(j, k[i]){
            int s_;
            cin >> s_;
            --s_;
            s[i].push_back(s_);
        }
    }

    rep(i, m) cin >> p[i];

    int res = 0;
    rep(i, 1<<n){
        vector<int> use(n, 0);
        rep(j, n){
            if(i & (1<<j)){
                use[j] = 1;
            }
        }

        bool flg = true;
        rep(j, m){
            int cnt = 0;
            rep(l, k[j]){
                cnt += use[s[j][l]];
            }

            if(cnt%2 != p[j]) flg = false;
        }

        if(flg) ++res;
    }

    cout << res << endl;

    return 0;
}