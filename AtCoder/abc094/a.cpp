#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, x;
    cin >> a >> b >> x;

    if(a<=x && x-a <= b) puts("YES");
    else puts("NO");
}