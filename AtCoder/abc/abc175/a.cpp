#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s == "RRR") cout << 3 << endl;
    else if((s[0] == 'R' && s[1] == 'R') || (s[1] == 'R' && s[2] == 'R')) cout << 2 << endl;
    else if(s[0] == 'R' || s[1] == 'R' || s[2] == 'R') cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}