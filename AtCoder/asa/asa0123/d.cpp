#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, m;
vector<string> a, b;

bool check(int y, int x){
    rep(i, m) rep(j, m){
        if(a[y+i][x+j] != b[i][j]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n-m+1) rep(j, n-m+1){
        if(check(i, j)){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}