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
    vector<int> a(n);
    ll xo = 0;
    rep(i, n){
        cin >> a[i];
        xo ^= a[i];
    }

    if(xo == 0) puts("second");
    else puts("first");


    return 0;
}