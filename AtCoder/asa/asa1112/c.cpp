#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> res(n, 0);
    rep(i, n-1){
        if(s[i]=='R' && s[i+1]=='L'){
            res[i] = 1;
            res[i+1] = 1;
        }
    }

    rep(i, n){
        if(res[i] == 0) continue;
        if(s[i] == 'L') continue;
        int cnt = 1;
        for(int j = i-1; j >= 0; --j){
            if(s[j] == 'L') break;
            if(cnt%2 == 0) ++res[i];
            else ++res[i+1];
            ++cnt;
        }
    }

    rep(i, n){
        if(res[i] == 0) continue;
        if(s[i] == 'R') continue;
        int cnt = 1;
        for(int j = i+1; j < n; ++j){
            if(s[j] == 'R') break;
            if(cnt%2 == 0) ++res[i];
            else ++res[i-1];
            ++cnt;
        }
    }

    for(auto e: res) cout << e << " ";
    cout << endl;

    return 0;
}