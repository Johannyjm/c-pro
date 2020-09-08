#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if(a[0]==b[2] && a[1]==b[1] && a[2]==b[0]) puts("Yes");
    else puts("No");
}