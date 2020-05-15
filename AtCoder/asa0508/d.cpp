#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> x(n), y(n);
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]) {
            int xt, yt;
            cin >> xt >> yt;
            --xt;
            x[i].push_back(xt);
            y[i].push_back(yt);
        }
    }

    int res = 0;
    rep(i, (1<<n)){
        vector<int> honest(n, 0);
        int sm = 0;
        rep(j, n){
            if(i & (1<<j)){
                honest[j] = 1;
                ++sm;
            }
        }

        bool is_correct = true;
        rep(j, n){
            if(honest[j] == 1){
                rep(k, a[j]){
                    if(y[j][k] == 0 && honest[x[j][k]] == 1) is_correct = false;
                    if(y[j][k] == 1 && honest[x[j][k]] == 0) is_correct = false;
                }
            }
        }

        if(is_correct) res = max(res, sm);

        // if(is_correct){
        //     rep(j, n) cout << honest[j] << " ";
        //     cout << endl;
        // }

    }

    cout << res << endl;

    return 0;
}