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

    vector<int> res(6, 0);
    rep(_, n){
        double mx, mn;
        cin >> mx >> mn;

        if(35 <= mx) ++res[0];
        if(30 <= mx && mx < 35) ++res[1];
        if(25 <= mx && mx < 30) ++res[2];
        if(25 <= mn) ++res[3];
        if(mn<0 && 0<=mx) ++res[4];
        if(mx < 0) ++res[5];
    }

    rep(i, 5) cout << res[i] << " ";
    cout << res[5] << endl;

    return 0;
}