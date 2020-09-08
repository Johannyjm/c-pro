#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    if(a>=b && a<=c || a>=c && a<=b) cout << a << endl;
    else if(b>=a && b<=c || b>=c && b<=a) cout << b << endl;
    else cout << c << endl;
}