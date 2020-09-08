#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    rep(i, 26){
        string ne = s+(char)('a' + i);
        if(t == ne){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}