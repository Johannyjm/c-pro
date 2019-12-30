#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int p, q, r;
    cin >> p >> q >> r;

    cout << min(p+q, min(q+r, r+p)) << endl;
}