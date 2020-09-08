#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if(n==2 || m==2) cout << 0 << endl;
    else if(min(n, m) == 1) cout << max(n, m) - 2 + 2*(max(n, m) == 1) << endl;
    else cout << (n-2) * (m-2) << endl;

}