#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d, n;
    cin >> d >> n;

    if(n==100)++n;

    cout << n;
    rep(i, d) cout << "00";

    cout << endl;
}