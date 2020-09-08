#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s = "";
    if(s=="") cout << 0 << endl;
    s = " ";
    if(s==" ") cout << 1 << endl;
    s = "ABC";
    if(s=="ABC") cout << 2 << endl;

    s += 'D';
    cout << s << endl;
    s += "EF";
    cout << s << endl;

    return 0;
}

