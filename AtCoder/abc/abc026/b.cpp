#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    int res = 0;

    rep(i, n){
        string s;
        int d;
        cin >> s >> d;

        if(s == "East") res += max(min(b, d), a);
        else res -= max(min(b, d), a);
    }

    if(res >= 0){
        if(res == 0) cout << 0 << endl;
        else cout << "East " << res << endl;
    }
    else cout << "West " << res << endl;


}