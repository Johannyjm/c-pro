#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, s, t, w;
    cin >> n >> s >> t >> w;

    int res = 0;
    if(s<=w && w<=t) ++res;
    for(int i = 1; i < n; ++i){
        int a;
        cin >> a;
        w += a;
        if(s<=w && w<=t) ++res;
    }
    cout << res << endl;
}