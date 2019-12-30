#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;
    int res = -1;

    for(int x = 0; x*2 <= a; ++x){
        int y = a-x;
        res = max(res, x*y);
    }
    cout << res << endl;
}