#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool nxt(char c1, char c2){
    if(c2-'0' == (c1-'0'+1) % 10) return true;
    else return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    

    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        puts("Weak");
        return 0;
    }

    if(nxt(s[0], s[1]) && nxt(s[1], s[2]) && nxt(s[2], s[3])){
        puts("Weak");
        return 0;
    }

    puts("Strong");

    return 0;
}