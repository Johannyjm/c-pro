#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    if(a>b && a>c) cout << 1 << endl;
    if((a>b && a<c) || (a<b && a>c)) cout << 2 << endl;
    if(a<b && a<c) cout << 3 << endl;

    if(b>a && b>c) cout << 1 << endl;
    if((b>a && b<c) || (b<a && b>c)) cout << 2 << endl;
    if(b<a && b<c) cout << 3 << endl;

    if(c>b && c>a) cout << 1 << endl;
    if((c>b && c<a) || (c<b && c>a)) cout << 2 << endl;
    if(c<b && c<a) cout << 3 << endl;


}