#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 12;
    int res = 0;
    rep(i, n){
        string s;
        cin >> s;

        bool flg = false;
        for(char c: s){
            if(c == 'r') flg = true;
        }

        if(flg) ++res;
    }

    cout << res << endl;

    return 0;
}