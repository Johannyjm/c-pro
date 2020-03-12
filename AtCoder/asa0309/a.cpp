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
    vector<int> d(n);
    rep(i, n) cin >> d[i];

    sort(d.begin(), d.end());

    cout << d[n/2] - d[n/2-1] << endl;

    return 0;
}