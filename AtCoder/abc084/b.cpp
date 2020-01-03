#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    string s;
    cin >> a >> b >> s;
    bool flg = true;

    for(int i = 0; i < s.length(); ++i){
        if(i<a && s[i]=='-') flg = false;
        if(i==a && s[i]!='-') flg = false;
        if(i>a && s[i]=='-') flg = false;
    }
    // if(flg) puts("Yes");
    // else puts("No");

    cout << (flg? "Yes": "No") << endl;
}