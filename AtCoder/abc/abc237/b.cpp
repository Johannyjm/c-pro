#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> res(w, vector<int>(h));
    rep(i, h) rep(j, w){
        int a;
        cin >> a;

        res[j][i] = a;
    }

    rep(i, w){
        rep(j, h-1) cout << res[i][j] << " ";
        cout << res[i].back() << endl;
    }


    return 0;
}