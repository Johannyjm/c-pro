#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int sum = 0;
    rep(i, m){
        int a;
        cin >> a;

        sum += a;
    }

    if(n-sum>=0) cout << n - sum << endl;
    else cout << -1 << endl;

    return 0;
}