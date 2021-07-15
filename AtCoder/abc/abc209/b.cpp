#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    rep(i, n){
        int a;
        cin >> a;
        if(i%2 == 1) --a;

        x -= a;

        if(x < 0){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}