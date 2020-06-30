#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d;
    cin >> d;

    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];

    vector<int> t(d);
    rep(i, d){
        cin >> t[i];
        --t[i];
    }

    vector<int> last(26, 0);
    int res = 0;
    rep(i, d){
        res += s[i][t[i]];
        
        int minus = 0;

        rep(j, 26) ++last[j];
        last[t[i]] = 0;
        rep(j, 26) minus += c[j] * last[j];

        res -= minus;
        cout << res << endl;
    }




    return 0;
}