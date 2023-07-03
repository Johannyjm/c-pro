#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 8;
    bool flg = true;

    int prev = 0;

    rep(_, n){
        int s;
        cin >> s;

        if(prev > s) flg = false;
        if(s < 100 || 675 < s) flg = false;
        if(s % 25 != 0) flg = false;

        prev = s;
    }

    if(flg) puts("Yes");
    else puts("No");
    

    return 0;
}