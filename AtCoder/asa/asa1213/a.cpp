#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> cnt(4, 0);
    rep(i, 3){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ++cnt[a];
        ++cnt[b];

        if(cnt[a] > 2 || cnt[b] > 2) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}