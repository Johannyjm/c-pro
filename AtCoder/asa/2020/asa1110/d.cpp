#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<int, int> cnt;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        ++cnt[a];
        ++cnt[b];
    }

    for(auto k: cnt){
        if(k.second % 2 == 1){
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}