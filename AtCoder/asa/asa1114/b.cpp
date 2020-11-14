#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string indeednow = "indeednow";
    vector<int> cnt(26, 0);
    for(char c: indeednow){
        ++cnt[c-'a'];
    }

    int n;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        vector<int> cnts(26, 0);
        for(char c: s){
            ++cnts[c-'a'];
        }

        if(cnt == cnts) puts("YES");
        else puts("NO");
    }

    return 0;
}