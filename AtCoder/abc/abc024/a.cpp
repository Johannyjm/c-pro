#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, k, s, t;
    cin >> a >> b >> c >> k >> s >> t;

    if(s+t < k) cout << a*s + b*t << endl;
    else cout << (a-c)*s + (b-c)*t << endl;
}