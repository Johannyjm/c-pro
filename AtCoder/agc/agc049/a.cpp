#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n){
        string s;
        cin >> s;
        rep(j, n){
            if(s[j] == 1){
                g[i].push_back(j);
            }
        }
    }

    puts("1");



    return 0;
}