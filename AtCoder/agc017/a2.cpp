#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main(){

    int n, p;
    cin >> n >> p;

    int odd = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(a%2) ++odd;
    }

    if(odd) cout << (1LL<<(n-1)) << endl;
    else {
        if(p) cout << 0 << endl;
        else cout << (1LL<<n) << endl;
    }

    return 0;
}