#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    rep1(i, 2000){
        if(i*8/100==a && i/10==b) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}