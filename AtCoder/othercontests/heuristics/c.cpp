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

    int m;
    cin >> m;

    vector<int> x(m), q(m);
    rep(i, m){
        cin >> x[i] >> q[i];
        --x[i];
        --q[i];
    }

    vector<vector<int>> last(d, vector<int>(26, 0));
    int res = 0;
    rep(i, d){
        res += s[i][t[i]];
        
        int minus = 0;

        rep(j, 26){
            if(i!=0) last[i][j] = last[i-1][j]+1;
            else ++last[i][j];
        }

        last[i][t[i]] = 0;
        rep(j, 26) minus += c[j] * last[i][j];

        res -= minus;
    }

    res = max(res, 0);

    rep(i, m){
        int day = x[i];
        int kind = q[i];

        res -= s[day][t[day]];
        res += s[day][kind];

        // orig minus;
        int minus = 0;
        for(int j = day; j < d; ++j){
            if(j!=day && last[j][t[day]] == 0) break;
            ++minus;

            if(j!=0) last[j][t[day]] = last[j-1][t[day]] + 1;
            else ++last[j][t[day]];
        }

        // switched plus;
        int plus = 0;
        last[day][kind] = 0;
        for(int j = day; j < d; ++j){
            if(j!=day && last[j][kind] == 0) break;
            ++plus;

            if(j!=day) last[j][kind] = last[j-1][kind] + 1;
            else ++last[j][kind];
        }

        cout << res - minus*c[t[day]] + plus*c[kind] << endl;


    }

    return 0;
}