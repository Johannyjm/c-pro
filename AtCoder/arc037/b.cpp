#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct UnionFind{
    vector<int> p;
    vector<int> r;
    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
    }

    int find(int x){
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    void unite(int x, int y){
        x = this->find(x);
        y = this->find(y);
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
    vector<int> isnot_tree;
    UnionFind uf(n);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if(uf.find(u) == uf.find(v)){
            isnot_tree.push_back(u);
        }
        else{
            uf.unite(u, v);
        }
    }

    map<int, int> ng_p;
    for(int i = 0; i < isnot_tree.size(); ++i) ++ng_p[uf.find(isnot_tree[i])];
    
    set<int> st;
    for(int i = 0; i < n; ++i){
        if(ng_p[uf.find(i)] == 0) st.insert(uf.find(i));
    }

    cout << st.size() << endl;

}
