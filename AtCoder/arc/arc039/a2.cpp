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

    int res = a - b;
    rep1(i, 10){
        int A = i*100 + a%100;
        res = max(res, A - b);
    }

    rep1(j, 10){
        int B = j*100 + b%100;
        res = max(res, a - B);
    }

    cout << res << endl;


    return 0;
}