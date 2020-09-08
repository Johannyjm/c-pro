#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> s(n, 0);
    rep(i, k){
        int d;
        cin >> d;
        rep(j, d){
            int a;
            cin >> a;
            --a;
            ++s[a];
        }
    }

    int res = 0;
    rep(i, n){
        if(s[i] == 0) ++res;
    }

    cout << res << endl;

    return 0;
}