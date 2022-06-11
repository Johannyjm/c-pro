#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int count2div(int n){
    int ret = 0;
    while(n % 2 == 0){
        ++ret;
        n /= 2;
    }
    
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int odd = 0;
    int even2 = 0;
    int even4p = 0;
    rep(i, n){
        int count = count2div(a[i]);
        if(count == 0) ++odd;
        if(count == 1) ++even2;
        if(count > 1) ++even4p;
    }

    if(odd <= even4p || (odd <= even4p+1)&&(even2 > 0)) puts("Yes");
    else puts("No");

    return 0;
}