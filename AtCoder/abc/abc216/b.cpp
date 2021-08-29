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
    unordered_map<string, unordered_map<string, int>> cnt;
    rep(i, n){
        string s, t;
        cin >> s >> t;
        cnt[s][t] += 1;
        if(cnt[s][t] == 2){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}