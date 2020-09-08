#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n;
    cin >> n;

    rep(i, n){
        int l, r;
        cin >> l >> r;

        string substr = s.substr(l-1, r-l+1);

        string lremain = s.substr(0, l-1);
        string rremain = s.substr(r, s.length()-r+1);

        for(int j = 0; j < substr.length(); ++j){
            substr[j] = s[r-j-1];
        }
        s = lremain + substr + rremain;
    }
    cout << s << endl;
}