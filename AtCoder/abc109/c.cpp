#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int gcd(int n, int m){
    int tmp;
    while(m%n){
        tmp = n;
        n = m%n;
        m = tmp;
    }

    return n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, X;
    cin >> n >> X;

    int res;
    cin >> res;
    res = abs(X - res);

    rep1(i, n){
        int x;
        cin >> x;
        res = gcd(res, abs(X - x));
    }
    cout << res << endl;

}