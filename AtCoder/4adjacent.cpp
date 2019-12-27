#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    //ll a[n];
    ll a;
    int four = 0;
    int odd = 0;
    int two = 0;
    rep(i, n){
        cin >> a;
        if(a%2) ++odd;
        else{
            if(a%4==0) ++four;
            else ++two;
        }
    }
    if(two){
        if(odd <= four) puts("Yes");
        else puts("No");
    }
    else{
        if(odd <= four+1) puts("Yes");
        else puts("No");
    }





}