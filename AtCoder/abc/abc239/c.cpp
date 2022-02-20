#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = -10; i <= 10; ++i) for(int j = -10; j <= 10; ++j){// for(int k = -10; k <= 10; ++k) for(int l = -10; l <= 10; ++l){
        ll x = a + i;
        ll y = b + j;

        ll d21 = (x - a)*(x - a) + (y - b)*(y - b);
        ll d22 = (x - c)*(x - c) + (y - d)*(y - d);

        if(d21 == 5 && d22 == 5){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}