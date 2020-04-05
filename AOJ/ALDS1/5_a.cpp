#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int q;
    cin >> q;
    rep(_, q){
        int m;
        cin >> m;

        bool flg = false;
        rep(i, 1<<n){
            int sum = 0;
            rep(j, n){
                if(i & (1<<j)) sum += a[j];
            }

            if(sum == m){
                flg = true;
                break;
            }
        }

        if(flg) puts("yes");
        else puts("no");
    }

    return 0;
}