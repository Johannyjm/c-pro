#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll c, m, y, w;
    cin >> c >> m >> y >> w;

    ll r, g, b;
    if(c == -1){
        b = w - y;
        r = m - b;
        g = y - r;
    }

    if(m == -1){
        b = w - y;
        g = c - b;
        r = y - g;
    }

    if(y == -1){
        r = w - c;
        g = w - m;
        b = m - r;
    }

    if(w == -1){
        b = (c + m - y) / 2;
        r = m - b;
        g = b + y - m;
    }

    cout << r << " " << g << " " << b << endl;

    return 0;
}