#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int a, b, c, d;
    cin >> s >> a >> b >> c >> d;

    rep(i, s.size()){
        if(i==a || i==b || i==c || i==d) cout << '"';
        cout << s[i];
    }
    if(d==s.size()) cout << '"';
    cout << endl;

    return 0;
}