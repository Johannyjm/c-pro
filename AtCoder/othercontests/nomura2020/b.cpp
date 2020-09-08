#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string t;
    cin >> t;

    string res = "";
    rep(i, t.size()){
        if(t[i] == '?') res += 'D';
        else res += t[i];
    }

    cout << res << endl;

    return 0;
}