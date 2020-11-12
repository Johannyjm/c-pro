#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    if(s == "{}"){
        puts("dict");
        return 0;
    }

    int l = 0;
    int r = 0;
    bool isdict = false;
    rep(i, n){
        if(s[i] == '{') ++l;
        if(s[i] == '}') ++r;
        
        if(l-r == 1){
            if(s[i] == ':') isdict = true;
        }
    }

    if(isdict) puts("dict");
    else puts("set");


    return 0;
}