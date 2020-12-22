#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    dsu uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        uf.merge(a, b);
    }

    set<int> st;
    rep(i, n) st.insert(uf.leader(i));

    cout << st.size()-1 << endl;



    return 0;
}