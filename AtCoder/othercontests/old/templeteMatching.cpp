#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string a[n], b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    bool flg = false;

    rep(i, n-m+1){
        rep(j, n-m+1){
            string sub = a[i].substr(j, m);

            if(sub == b[0]){
                flg = true;
                rep(k, m){
                    sub = a[i+k].substr(j, m);

                    if(sub == b[k]) flg = flg && true;
                    else flg = false;
                }
                if(flg) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
}