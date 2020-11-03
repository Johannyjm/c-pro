#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, d;
vector<vector<int>> x;

int calcdist2(int i, int j){
    int ret = 0;
    rep(idx, d){
        ret += (x[j][idx] - x[i][idx])*(x[j][idx] - x[i][idx]);
    }

    return ret;
}

bool issquared(int d){
    for(int i = 1; i*i <= d; ++i){
        if(i*i == d) return true;
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> d;

    x.resize(n, vector<int>(d));
    rep(i, n) rep(j, d) cin >> x[i][j];

    int res = 0;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            int dist2 = calcdist2(i, j);

            if(issquared(dist2)) ++res;
        }
    }

    cout << res << endl;

    return 0;
}