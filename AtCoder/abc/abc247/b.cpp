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

    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i] >> t[i];


    rep(i, n){
        
        bool s_unuse = true;
        bool t_unuse = true;
        rep(j, n){
            if(i == j) continue;
            if(s[i] == s[j] || s[i] == t[j]) s_unuse = false;
            if(t[i] == s[j] || t[i] == t[j]) t_unuse = false;
        }

        if(!s_unuse && !t_unuse){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}