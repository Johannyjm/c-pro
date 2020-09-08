#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, a, b;
    cin >> w >> a >> b;

    if((a<=b && b<=a+w) || (a<=b+w && b+w<=a+w)) cout << 0 << endl;
    else cout << min(abs(b+w-a), abs(a+w-b)) << endl;
}