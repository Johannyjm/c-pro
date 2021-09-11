#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<string, int> mp;
    rep(i, 3){
        string s;
        cin >> s;
        ++mp[s];
    }

    if(mp["ABC"] == 0) puts("ABC");
    if(mp["ARC"] == 0) puts("ARC");
    if(mp["AGC"] == 0) puts("AGC");
    if(mp["AHC"] == 0) puts("AHC");


    return 0;
}