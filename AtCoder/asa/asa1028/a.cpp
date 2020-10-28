#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

    int w;
    cin >> w;
    int n = s.size() / w;

    rep(i, n){
        rep(j, w) cout << s[i*w + j];
        cout << endl;
    }

    rep(j, s.size()%w) cout << s[n*w + j];
    if(s.size()%w!=0) cout << endl;

    return 0;
}