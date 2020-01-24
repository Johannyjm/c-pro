#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    const string k = "keyence";
    if(s.substr(0, 7)==k || s.substr(n-7, 7)==k){
        puts("YES");
        return 0;
    }

    rep1(i, 7){
        string l = k.substr(0, i);
        string r = k.substr(i, 7-i);

        cout << l << " " << r << endl;
        cout << s.substr(0, i) << " " << s.substr(n-7+i, 7-i) << endl << endl;

        if(s.substr(0, i)==l && s.substr(n-7+i, 7-i)==r){
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}