#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<int>> rooted_to_graph(vector<int> parent){
    int n = parent.size();
    vector<vector<int>> ret(n);
    rep(i, n){
        if(parent[i] == -1) continue;

        ret[i].push_back(parent[i]);
        ret[parent[i]].push_back(i);
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    p[0] = -1;
    rep1(i, n){
        cin >> p[i];
        --p[i];
    }
    for(auto elem: p) cout << elem << " ";
    cout << endl;

    vector<vector<int>> g = rooted_to_graph(p);
    rep(i, n){
        cout << i << ": " << endl;
        for(auto nv: g[i]) cout << nv << " ";
        cout << endl;
    }

    return 0;
}