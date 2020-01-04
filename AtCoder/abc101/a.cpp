#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int res = 0;

    rep(i, 4){
        if(s[i] == '+') ++res;
        else --res;
    }
    cout << res << endl;
}