#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct UnionFind{
    
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    UnionFind uf(28);
    for(int i = 0; i < n; ++i){
        if(!('0'<=s[i] && s[i]<='9' && '0'<=t[i] && t[i]<='9')) uf.unite(s[i]-'0', t[i]-'0');
        if(i == 0) uf.unite(s[i]-'0', 26);
        if('0' <= s[i] && s[i] <= '9') uf.unite(s[i]-'0', 27);
        if('0' <= t[i] && t[i] <= '9') uf.unite(t[i]-'0', 27);
    }

    ll res = 1;
    vector<bool> seen(n, false);
    for(int i = 0; i < n; ++i){
        if(seen[i]) continue;
        if(uf.find(s[i]-'0') == uf.find(27)) continue;
        if(uf.find(s[i]-'0') == uf.find(26)){
            res *= 9;
        }
        else{
            res *= 10;
        }
        for(int j = 0; j < n; ++j){
            if(uf.find(s[i]-'0') == uf.find(s[j]-'0')) seen[j] = true;
        }
    }

    cout << res << endl;

    return 0;
}
