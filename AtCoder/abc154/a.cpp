#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t, u;
    int a, b;

    cin >> s >> t >> a >> b >> u;

    if(u==s) --a;
    if(u==t) --b;
    cout << a << " " << b << endl;

    return 0;
}