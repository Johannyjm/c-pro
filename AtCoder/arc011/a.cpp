#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, n, N;
    cin >> m >> n >> N;

    int res = N;

    while(N>=m){
        res += N/m * n;
        N = N/m * n + N%m;
    }

    cout << res << endl;

    return 0;
}