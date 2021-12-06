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
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    rep(i, n) rep(j, m-1){
        if(a[i][j] + 1 != a[i][j+1]){
            puts("No");
            return 0;
        }
    }

    rep(j, m) rep(i, n-1){
        if(a[i][j] + 7 != a[i+1][j]){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}