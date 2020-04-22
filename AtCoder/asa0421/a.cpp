#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int a, b;
    cin >> a >> b;

    string u;
    cin >> u;

    if(u == s) --a;
    else --b;

    cout << a << " " << b << endl;

    return 0;
}