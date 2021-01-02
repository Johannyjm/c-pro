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
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    vector<int> cnt(110, 0);
    ++cnt[a];
    ++cnt[b];
    rep(_, k){
        int p;
        cin >> p;
        if(cnt[p] > 0){
            puts("NO");
            return 0;
        }
        ++cnt[p];
    }

    puts("YES");

    return 0;
}