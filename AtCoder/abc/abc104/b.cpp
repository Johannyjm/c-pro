#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool flg1 = false;
    bool flg2 = false;
    bool flg3 = true;
    int cidx = 0;

    if(s[0] == 'A') flg1 = true;
    else flg1 = false;

    for (int i = 2; i < s.length()-1; ++i){
        if(s[i] == 'C') {
            flg2 = flg2 || true;
            cidx = i;
            }
        else flg2 = flg2 || false;
    }

    for (int i = 1; i < s.length(); ++i){
        if(('a'<=s[i] && s[i]<='z') || i==cidx) flg3 = flg3 && true;
        else flg3 = false;
        
    }

    if(flg1 && flg2 && flg3) puts("AC");
    else puts("WA");
}