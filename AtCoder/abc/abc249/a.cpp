#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;

    int takahashi = x / (a+c) * b * a;
    takahashi += min(x % (a+c), a) * b;

    int aoki = x / (d+f) * e * d;
    aoki += min(x % (d+f), d) * e;

    if(takahashi == aoki){
        puts("Draw");
    }
    else if(takahashi > aoki){
        puts("Takahashi");
    }
    else{
        puts("Aoki");
    }

    return 0;
}