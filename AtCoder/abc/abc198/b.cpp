#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_palindrome(string s){
    int n = s.size();
    rep(i, n){
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    rep(i, 10){
        string now = "";
        rep(j, i) now += '0';
        now += s;

        if(is_palindrome(now)){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}