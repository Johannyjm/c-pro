#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int res = 1000;

    rep(i, s.length()-2){
        string sub = s.substr(i, 3);
        
        int n = 100 * (sub[0] - '0') + 10 * (sub[1] - '0') + (sub[2] - '0');
        res = min(res, abs(753-n));
    }
    cout << res << endl;
}