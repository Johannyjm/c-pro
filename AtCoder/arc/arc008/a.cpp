#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n<=6) cout << 15*n << endl;
    else if(7<=n%10 && n%10<10) cout << (n+9)/10*100 << endl;
    else cout << n/10*100 + n%10*15 << endl;

    return 0;
}