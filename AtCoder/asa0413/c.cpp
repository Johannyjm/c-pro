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

    map<int, int> mp;
    int res = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(mp[a]) ++res;
        else ++mp[a];
    }

    cout << res << endl;

    return 0;
}