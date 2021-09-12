#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    rep(i, x+1){
        if(i*2 + (x-i)*4 == y){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}