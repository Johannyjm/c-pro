#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b, c;
    cin >> a >> b >> c;

    if(a[a.length()-1] == b[0] && b[b.length()-1] == c[0]) puts("YES");
    else puts("NO");
}