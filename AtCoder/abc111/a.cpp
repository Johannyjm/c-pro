#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string n;
    cin >> n;

    rep(i, n.length()){
        cout << 10 - (n[i] - '0');
    }
    cout << endl;
}