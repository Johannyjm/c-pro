#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<int, int> road;
    rep(i, m){
        int a, b;
        cin >> a >> b;

        ++road[a];
        ++road[b];
    }
    rep1(i, n+1){
        cout << road[i] << endl;
    }

    return 0;
}