#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int gcd(int x, int y){
    if(x == 0) return y;
    else return gcd(y%x, x);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}