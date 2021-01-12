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

    map<string, int> cnt;
    int mx = 0;
    rep(i, n){
        string s;
        cin >> s;

        ++cnt[s];
        mx = max(mx, cnt[s]);
    }

    for(auto k: cnt){
        if(k.second == mx){
            cout << k.first << endl;
        }
    }

    return 0;
}