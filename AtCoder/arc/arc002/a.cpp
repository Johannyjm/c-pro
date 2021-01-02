#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int y;
    cin >> y;

    if(y%4 == 0){
        if(y%100 == 0){
            if(y%400 == 0) puts("YES");
            else puts("NO");
        }
        else puts("YES");
    }
    else puts("NO");

    return 0;
}