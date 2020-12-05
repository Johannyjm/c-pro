#include <iostream>
#include <vector>
#include <algorithm>
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
        else return p[x] = leader(p[x]);
    }

    void merge(int x, int y){
        x = leader(x);
        y = leader(y);
        
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++r[y];

        p[x] = y;
    }

    bool same(int x, int y){
        return leader(x) == leader(y);
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    for(int i = 0; i < q; ++i){
        int cmd;
        cin >> cmd;

        if(cmd == 0){
            int x, y;
            cin >> x >> y;
            uf.merge(x, y);
        }

        if(cmd == 1){
            int x, y;
            cin >> x >> y;
            cout << uf.same(x, y) << endl;
        }
    }
}