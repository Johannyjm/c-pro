#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<vector<int>> blank(n, vector<int>(n, 0)); // 0: o, 1: .
    rep(i, n) rep(j, n){
        if(s[i][j] == '.') blank[i][j] = 1;
    }

    auto paint = [&](int r, int c){
        for(int i = 0; i <= c; ++i) blank[r][i] = 0;
        for(int i = c; i < n; ++i) blank[r+1][i] = 0;
    };

    int res = 0;
    rep(i, n-1){
        int last_blank = -1;
        rep(j, n){
            if(blank[i][j] == 1) last_blank = j;
        }

        if(last_blank >= 0){
            paint(i, last_blank);
            ++res;
        }
    }

    rep(i, n){
        if(blank[n-1][i] == 1){
            cout << res+1 << endl;
            return 0;
        }
    }

    cout << res << endl;

    return 0;
}