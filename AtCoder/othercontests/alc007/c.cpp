#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int res = 0;

    for (int i = 0; i <= (n+r-1)/r; ++i){
        for (int j = 0; j <= (n+g-1)/g; ++j){
            for (int k = 0; k <= (n+b-1)/b; ++k){
                if(r*i + g*j + b*k == n) ++res;
            }
        }
    }

    cout << res << endl;

    return 0;
}