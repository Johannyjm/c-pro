#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    unordered_set<int> ast, bst;
    rep(i, n){
        cin >> a[i];
        ast.insert(a[i]);
    }
    rep(i, m){
        cin >> b[i];
        bst.insert(b[i]);
    }

    vector<int> res;
    rep(i, n){
        if(bst.count(a[i]) == 0){
            res.push_back(a[i]);
        }
    }
    rep(i, m){
        if(ast.count(b[i]) == 0){
            res.push_back(b[i]);
        }
    }

    sort(res.begin(), res.end());

    for(auto e: res) cout << e << " ";
    cout << endl;

    return 0;
}