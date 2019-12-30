#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    s = s + '?';

    char prev = s[0];
    int cnt = 1;
    for(int i = 1; i < s.length(); ++i){

        if(s[i] == prev) {
            ++cnt;
        }
        else {
            cout << s[i-1] << cnt;
            cnt = 1;
        }
        prev = s[i];
    }
    cout << endl;
}