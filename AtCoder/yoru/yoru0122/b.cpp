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

    vector<int> cnt(26, 0);
    for(auto c: s) ++cnt[c - 'a'];

    rep(i, 26){
        if(cnt[i] == 0){
            cout << char('a' + i) << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}