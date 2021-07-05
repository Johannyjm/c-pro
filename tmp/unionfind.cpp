#include <iostream>
#include <vector>
using namespace std;

struct UnionFind{
    vector<int> p;
    vector<int> r;

    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
    }

    int leader(int x){
        if(p[x] == -1) return x;
        return p[leader(x)] = leader(x);
    }

    void unite(int x, int y){
        x = leader(x);
        y = leader(y);

        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++r[y];

        p[x] = y;
    }
};


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
}
