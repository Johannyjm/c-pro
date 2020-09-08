#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int d = a+b;
    int e = a-b;

    if(d==c && e!=c)puts("+");
    else if(e==c && d!=c)puts("-");
    else if(d!=c && e!=c)puts("!");
    else if(d==e)puts("?");
}