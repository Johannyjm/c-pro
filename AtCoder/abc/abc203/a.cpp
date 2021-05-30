#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if(a == b) cout << c;
    else if(b == c) cout << a;
    else if(c == a) cout << b;
    else cout << 0;

    cout <<  endl;

    return 0;
}