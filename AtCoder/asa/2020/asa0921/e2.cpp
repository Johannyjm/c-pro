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
    rep(i, n){
        idx[s[i] - 'a'].push_back(i);
    }
    rep(i, 26){
        sort(idx[i].begin(), idx[i].end());
    }

    rep(i, 26){
        for(auto el: idx[i]) cout << el << " ";
        cout << endl;
    }

    ll res = 0;
    if(idx[t[0] - 'a'].empty()){
        cout << -1 << endl;
        return 0;
    }

    int ptr = idx[0].front();
    rep1(i, m){
        int now = t[i] - 'a';
        if(idx[now].empty()){
            cout << -1 << endl;
            return 0;
        }

        if(idx[now].size() == 1){
            if(idx[now].front() < ptr) res += n;
            else ptr = idx[now].front();
        }

    }

    return 0;
}