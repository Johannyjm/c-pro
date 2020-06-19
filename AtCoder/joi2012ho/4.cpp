#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> imos(n, vector<int>(n+1, 0));
    rep(i, m){
        int a, b, x;
        cin >> a >> b >> x;
        --a, --b;

        rep(j, x+1){
            int row = a+j;
            int from = b;
            int to = b+j;

            ++imos[row][from];
            --imos[row][to+1];
        }
    }

    rep(i, n) rep1(j, n+1){
        imos[i][j] += imos[i][j-1];
    }

    int res = 0;
    rep(i, n) rep(j, n){
        if(imos[i][j] > 0) ++res;
    }

    cout << res << endl;

    return 0;
}