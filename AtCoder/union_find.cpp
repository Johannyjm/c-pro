#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

vector<ll> dp;
 
void init(ll n) {
    dp.resize(n);
    rep(i, n) dp[i] = i;
}

ll root(ll x) {
    if (dp[x] == x) return x;
    else return dp[x] = root(dp[x]);
}

void unite(ll x, ll y) {
    auto rx = root(x);
    auto ry = root(y);
    dp[ry] = dp[rx];
    root(y);
}

bool same(ll x, ll y) {
    return root(x) == root(y);
}


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

struct UnionFind {
    vector<int> p;
    vector<int> r;

    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
    }

    int find(int x){
        if(p[x] == -1) return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++r[y];

        p[x] = y;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    rep(i, q){
        int com, a, b;
        cin >> com >> a >> b;

        if(com) {
            if(uf.find(a) == uf.find(b)) puts("Yes");
            else puts("No");
        }
        
        else uf.unite(a, b);
    }

    return 0;
}