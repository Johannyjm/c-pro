#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >>c >> d;

    int dx = c - a;
    int dy = d - b;

    int e = c - dy;
    int f = d + dx;

    int g = e - dx;
    int h = f - dy;

    cout << e << " " << f << " " << g << " " << h << endl;

}