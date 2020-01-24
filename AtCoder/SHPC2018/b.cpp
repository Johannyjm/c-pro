#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int w;
    cin >> s >> w;

    rep(i, s.size()){
        if(i%w == 0) cout << s[i];
    }
    cout << endl;

    return 0;
}