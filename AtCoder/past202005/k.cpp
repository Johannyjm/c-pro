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

    vector<int> parent(n);
    rep(i, n) parent[i] = i;

    int q;
    cin >> q;
    rep(_, q){
        int f, t, x;
        cin >> f >> t >> x;
        --f;
        --t;
        --x;

        
    }


    return 0;
}