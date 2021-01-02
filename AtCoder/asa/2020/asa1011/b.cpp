#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 6;
    vector<int> e(n), l(n);
    rep(i, n) cin >> e[i];
    int b;
    cin >> b;
    rep(i, n) cin >> l[i];

    int cnt = 0;
    int bonus = 0;
    rep(i, n){
        if(e[i] == l[i]) ++cnt;
        else{
            if()
        }
    }

    return 0;
}