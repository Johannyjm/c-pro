#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int min_a = 1001, max_a = -1;
    rep(i, n) {
        int a;
        cin >> a;
        min_a = min(min_a, a);
        max_a = max(max_a, a);
    }
    cout << max_a - min_a << endl;
}