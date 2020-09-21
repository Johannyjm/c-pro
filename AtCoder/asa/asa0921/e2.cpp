#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vector<vector<int>> idx(26);
    for(int i = 0; i < n; ++i){
        idx[s[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < 26; ++i){
        sort(idx[i].begin(), idx[i].end());
    }

    for(int i = 0; i < 26; ++i){
        for(auto el: idx[i]) cout << el << " ";
        cout << endl;
    }

    return 0;
}