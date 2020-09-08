#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(abs(c-a)<=d || (abs(b-a)<=d && abs(c-b)<=d)) puts("Yes");
    else puts("No");
}