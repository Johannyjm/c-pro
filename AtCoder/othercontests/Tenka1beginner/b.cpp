#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int max_a = -1;
    int res;

    rep(i, n){
        int a, b;
        cin >> a >> b;

        if(a > max_a){
            max_a = a;
            res = b;
        }
    }

    cout << res + max_a << endl;

    return 0;
}