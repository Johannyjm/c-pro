#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool ispali(string s){
    int n = s.size();
    rep(i, n / 2){
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;

    int n = s.size();
    vector<int> drop(n, 0);
    rep(i, n){
        if(s[i] == 'a') drop[i] = 1;
        else break;
    }
    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'a') drop[i] = 1;
        else break;
    }

    string dropa = "";
    rep(i, n){
        if(drop[i] != 1) dropa += s[i];
    }

    if(ispali(dropa)) puts("Yes");
    else puts("No");

    return 0;
}