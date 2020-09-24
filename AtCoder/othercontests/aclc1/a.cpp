#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }

    



    return 0;
}