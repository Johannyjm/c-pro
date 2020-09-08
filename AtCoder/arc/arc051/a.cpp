#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

    string res1 = "YES";
    string res2 = "YES";

    if(x2<=x1-r && x1+r<=x3 && y2<=y1-r && y1+r<=y3){
        res1 = "NO";
    }

    int d_squared1 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int d_squared2 = (x1-x3)*(x1-x3) + (y1-y2)*(y1-y2);
    int d_squared3 = (x1-x2)*(x1-x2) + (y1-y3)*(y1-y3);
    int d_squared4 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    if(max(d_squared1, max(d_squared2, max(d_squared3, d_squared4))) <= r*r){
        res2 = "NO";
    }

    cout << res1 << "\n" << res2 << endl;

    return 0;
}