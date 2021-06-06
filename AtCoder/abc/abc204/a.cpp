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

    if(x == y) cout << x << endl;
    else{
        cout << 3 - x - y << endl;
    }

    return 0;
}