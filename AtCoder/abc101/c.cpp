#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int _;
    rep(i, n) cin >> _;

    int res = 0;
    int area = 1;

    while(area < n){
        area += k-1;
        ++res;
    }
    cout << res << endl;
}