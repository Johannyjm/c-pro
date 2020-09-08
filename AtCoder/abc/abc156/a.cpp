#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, r;
    cin >> n >> r;

    if(n<10) cout << r + 100 * (10 - n) << endl;
    else cout << r << endl;
    
    return 0;
}