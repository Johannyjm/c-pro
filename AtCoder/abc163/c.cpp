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

    vector<int> bucket(n, 0);
    rep(i, n-1){
        int a;
        cin >> a;
        --a;

        ++bucket[a];
    }

    rep(i, n) cout << bucket[i] << endl;

    return 0;
}