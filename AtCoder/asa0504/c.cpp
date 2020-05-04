#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
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

    vector<int> abc(3, 0);
    rep(i, n) ++abc[s[i] - 'a'];
    
    bool res = false;
    if(n==1) res = true;
    else if(n==2){
        if(s[0] != s[1]) res = true;
    }
    else{
        if(max({abc[0], abc[1], abc[2]}) <= min({abc[0], abc[1], abc[2]}) + 1) res = true;
    }

    if(res) puts("YES");
    else puts("NO");

    return 0;
}