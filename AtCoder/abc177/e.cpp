#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << gcd(7, 7) << endl;

    int n;
    cin >> n;
    vector<ll> a(n);
    bool flg = true;
    ll g, h;
    rep(i, n){
        cin >> a[i];
        
        if(i == 0){
            g = a[i];
            h = a[i];
        }
        else{
            g = gcd(g, a[i]);
            h = gcd(a[i-1], a[i]);
            if(h > 1) flg = false;
        }
    }

    if(flg){
        puts("pairwise coprime");
        return 0;
    }


    if(g > 1){
        puts("not coprime");
        return 0;
    }
    
    puts("setwise coprime");



    return 0;
}