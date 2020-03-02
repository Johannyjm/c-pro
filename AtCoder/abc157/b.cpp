#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a[3][3];
    rep(i, 3) rep(j, 3) cin >> a[i][j];

    int n;
    cin >> n;

    rep(_, n){
        int b;
        cin >> b;

        rep(i, 3) rep(j, 3){
            if(a[i][j] == b) a[i][j] = 0;
        }
    }

    if(a[0][0]+a[0][1]+a[0][2]==0 || a[1][0]+a[1][1]+a[1][2]==0 || a[2][0]+a[2][1]+a[2][2]==0 || a[0][0]+a[1][0]+a[2][0]==0 || a[0][1]+a[1][1]+a[2][1]==0 || a[0][2]+a[1][2]+a[2][2]==0 || a[0][0]+a[1][1]+a[2][2]==0 || a[0][2]+a[1][1]+a[2][0]==0){
        puts("Yes");
    }
    else puts("No");

    return 0;
}