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

    if(x%y == 0) {
        cout << -1 << endl;
        return 0;
    }

    int base = 2;
    while(1){
        int res = x*base;
        if(res % y){
            cout << res << endl;
            return 0;
        }
        ++base;
    }


    return 0;
}