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
    map<char, int> mp;
    rep(i, (int)s.size()){
        ++mp[s[i]];
    }

    for(auto k: mp){
        rep(_, k.second*2) cout << k.first;
    }

    cout << endl;

    return 0;
}