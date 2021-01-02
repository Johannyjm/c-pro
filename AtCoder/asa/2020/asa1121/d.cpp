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
    vector<int> a(n), b(n), diff(n);
    ll sma = 0;
    ll smb = 0;
    rep(i, n){
        cin >> a[i];
        sma += a[i];
    }
    rep(i, n){
        cin >> b[i];
        smb += b[i];
        diff[i] = a[i] - b[i];
    }

    if(a == b){
        puts("Yes");
        return 0;
    }
    
    ll cnt = smb - sma;

    ll c = 0;
    rep(i, n){
        if(a[i] < b[i]) c += (b[i] - a[i] + 1) / 2;
    }

    if(c <= cnt) puts("Yes");
    else puts("No");


    return 0;
}