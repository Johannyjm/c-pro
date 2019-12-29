#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int t;
    cin >> s >> t;
    int ud = 0;
    int lr = 0;
    int q = 0;

    for (int i = 0; i < s.length(); ++i){
        char c = s[i];
        switch (c)
        {
        case 'U':
            ++ud;
            break;
        case 'D':
            --ud;
            break;
        case 'R':
            ++lr;
            break;
        case 'L':
            --lr;
            break;
        case '?':
            ++q;
            break;
        default:
            break;
        }
    }
    int len = s.length();
    if(t-1) cout << max(abs(lr) + abs(ud) - q, len%2) << endl;
    else cout << abs(lr) + abs(ud) + q << endl;
}