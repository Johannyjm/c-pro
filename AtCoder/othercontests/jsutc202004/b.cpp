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

    vector<pair<int, int>> p(n);
    rep(i, n){
        int x;
        char c;
        cin >> x >> c;

        p[i] = make_pair(c == 'R'? 0: 1, x);
    }

    sort(p.begin(), p.end());
    
    rep(i, n){
        cout << p[i].second << endl;
    }

    return 0;
}