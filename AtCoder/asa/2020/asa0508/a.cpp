#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(_, w+2) cout << '#';
    cout << endl;
    rep(i, h) {
        cout << '#';
        rep(j, w){
            cout << a[i][j];
        }
        cout << '#' << endl;
    }
    rep(_, w+2) cout << '#';
    cout << endl;

    return 0;
}