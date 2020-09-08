#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned int n, h, w;
    cin >> n >> h >> w;

    unsigned int res = 0;
    rep(i, n){
        unsigned int a, b;
        cin >> a >> b;

        if(a>=h && b>=w) ++res;
    }

    cout << res << endl;

    return 0;
}