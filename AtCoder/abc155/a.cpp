#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    set<int> s;
    int a, b, c;
    cin >> a >> b >> c;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    if(s.size() == 2) puts("Yes");
    else puts("No");

    return 0;
}