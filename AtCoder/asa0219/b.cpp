#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int b = 0;
    rep(i, n){
        if(s[i] == 'B') ++b;
    }

    int res = 0;
    int ptr = 0;
    rep(i, n){
        if(s[i] == 'B'){
            res += n - b - i + ptr;
            ++ptr;
        }
    }

    cout << res << endl;

    return 0;
}