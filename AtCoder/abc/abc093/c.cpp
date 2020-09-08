#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int n_max = max(a, max(b, c));
    int sum_diff = n_max-a + n_max-b + n_max-c;

    if(sum_diff%2 == 0) cout << sum_diff/2 << endl;
    else cout << (sum_diff+3)/2 << endl;
}