#include <iostream>
#include <vector>
using namespace std;

struct DisjointSetUnion{
    vector<int> p;
    vector<int> r;

    DisjointSetUnion(int n){
        p.resize(n, -1);
        r.resize(n, 1);
    }

    int leader(int x){
        if(p[x] == -1) return x;
        return p[x] = leader(p[x]);
    }

    void merge(int x, int y){
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

    int n, q;
    cin >> n >> q;

    DisjointSetUnion uf(n);
    while(q--){
        int p, a, b;
        cin >> p >> a >> b;

        if(p == 0){
            uf.merge(a, b);
        }
        if(p == 1){
            if(uf.leader(a) == uf.leader(b)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
