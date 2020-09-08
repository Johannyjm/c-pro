#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int h, w;
vector<string> a;
vector<vector<int>> cake;
void dfs(int i, int j){
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> h >> w >> k;

    a.resize(h);
    rep(i, h) cin >> a[i];

    cake.resize(h, vector<int>(w, 0));

    rep(i, h) rep(j, w){
        if(a[i][j] == '#'){
            dfs(i, j);
        }
    }

    rep(i, h){
        rep(j, w) cout << cake[i][j] << " ";
        cout << endl;
    }

    return 0;
}