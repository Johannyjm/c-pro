#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 4;
    vector<int> a(n);
    rep(i, n){
        rep(j, n) cin >> a[j];

        if(a[0]==a[1] || a[1] == a[2] || a[2]==a[3]){
            puts("CONTINUE");
            return 0;
        }
    }

    puts("GAMEOVER");

    return 0;
}