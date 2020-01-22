#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, d;
    cin >> m >> d;
    int res = 0;
    rep1(i, m+1){
        for(int j = 11; j <= d; ++j){
            int a = j/10;
            int b = j%10;

            if(a==1 || b==1) continue;

            if(a*b==i) ++res;
        }
    }
    cout << res << endl;

    return 0;
}