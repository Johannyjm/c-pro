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

    bool flg = false;
    rep(i, n){
        if(s[i] == 'C') flg = true;
        if(flg && s[i] == 'F'){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}