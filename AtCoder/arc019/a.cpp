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

    rep(i, s.size()){
        if(s[i]=='O' || s[i]=='D') cout << 0;
        else if(s[i]=='I') cout << 1;
        else if(s[i]=='Z') cout << 2;
        else if(s[i]=='S') cout << 5;
        else if(s[i]=='B') cout << 8;
        else cout << s[i];
    }
    cout << endl;

    return 0;
}