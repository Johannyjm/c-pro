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

    int cnt = 0;
    rep(i, n){
        if(s[i] == '{') ++cnt;
        if(s[i] == '}') --cnt;
        if(s[i]!='{' && s[i]!='}') continue;
        
        if(i > 0 && cnt == 1){
            if(i+1<n && s[i+1] == ','){
                puts("set");
                return 0;
            }
            if(i+1<n && s[i+1] == ':'){
                puts("dict");
                return 0;
            }
        }
    }

    cnt = 0;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '}') ++cnt;
        if(s[i] == '{') --cnt;
        if(s[i]!='{' && s[i]!='}') continue;
        
        if(i < n-1 && cnt == 1){
            if(i-1>=0 && s[i-1] == ','){
                puts("set");
                return 0;
            }
            if(i-1>=0 && s[i-1] == ':'){
                puts("dict");
                return 0;
            }
        }
    }

    rep(i, n){
        if(s[i] == ','){
            puts("set");
            return 0;
        }
        if(s[i] == ':'){
            puts("dict");
            return 0;
        }
    }


    return 0;
}