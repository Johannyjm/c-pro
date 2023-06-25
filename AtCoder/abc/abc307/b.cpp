#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_palindrome(string s){
    int n = s.size();

    rep(i, n / 2){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    rep(i, n) rep(j, n){
        if(i == j) continue;

        string cand = s[i] + s[j];

        if(is_palindrome(cand)){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}