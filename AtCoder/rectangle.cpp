#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    if(l1 == l2) cout << l3 << endl;
    else if(l1 == l3) cout << l2 << endl;
    else cout << l1 << endl;
}