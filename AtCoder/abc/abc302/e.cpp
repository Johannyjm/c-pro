#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;


const int MAX_N = 3e5 + 5;
int edgeCount[MAX_N];
set<int> unconnected;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        unconnected.insert(i);
        edgeCount[i] = 0;
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            edgeCount[u]++;
            edgeCount[v]++;
            unconnected.erase(u);
            unconnected.erase(v);
        } else {
            int v;
            cin >> v;
            if (edgeCount[v] > 0) {
                edgeCount[v] = 0;
                unconnected.insert(v);
            }
        }
        cout << unconnected.size() << endl;
    }

    return 0;
}