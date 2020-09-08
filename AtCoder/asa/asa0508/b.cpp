#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    map<int, int> mp;
    vector<int> idx(n, -1);
    rep(i, n){
        int a;
        cin >> a;
        --a;
        if(idx[a] == i) ++res;
        idx[i] = a;
    }
    cout << res << endl;

    return 0;
}