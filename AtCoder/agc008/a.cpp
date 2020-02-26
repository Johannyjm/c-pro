#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int res;
    if(x < y){
        if(0 <= x) res = y - x;
        if(x<0 && 0<y){
            if(abs(y) < abs(x)) res = abs(x)-abs(y) + 1;
            else res = abs(y) - abs(x) + 1;
        }
        if(y <= 0) res = abs(x) - abs(y);
    }

    else{
        if(x < 0) res = abs(y)-abs(x) + 2;
        if(y<=0 && 0<=x){
            if(abs(y) < abs(x)) res = abs(x)-abs(y) + 1;
            else res = abs(y)-abs(x) + 1;
        }
        if(0 < y) res = x - y + 2;
    }

    cout << res << endl;

    return 0;
}