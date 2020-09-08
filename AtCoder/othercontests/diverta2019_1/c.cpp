#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int countAB(string s){
    int ret = 0;
    rep(i, s.size()-1){
        if(s[i]=='A' && s[i+1]=='B') ++ret;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> s(n);
    int res = 0;
    int frontB = 0;
    int backA = 0;
    int both = 0;
    rep(i, n){
        cin >> s[i];
        res += countAB(s[i]);
        if(s[i].front() == 'B' && s[i].back() == 'A') ++both;
        if(s[i].front() == 'B') ++frontB;
        if(s[i].back() == 'A') ++backA;
    }
    res += min(frontB, backA);
    if(frontB != 0 && frontB==backA && backA==both) --res;

    cout << res  << endl;

    return 0;
}