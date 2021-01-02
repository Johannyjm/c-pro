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

    int a, b, c, d;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';

    string op;
    if(a+b+c+d==7) op = "+++";
    if(a+b+c-d==7) op = "++-";
    if(a+b-c+d==7) op = "+-+";
    if(a+b-c-d==7) op = "+--";
    if(a-b+c+d==7) op = "-++";
    if(a-b+c-d==7) op = "-+-";
    if(a-b-c+d==7) op = "--+";
    if(a-b-c-d==7) op = "---";
    
    rep(i, 3) cout << s[i] << op[i];
    cout << s[3] << "=7" << endl;

    return 0;
}