#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;



vector<int> rooted_tree(vector<vector<int>> g, int r=0){
    vector<int> ret(g.size(), -1);
    stack<int> st;
    st.push(r);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(int nv: g[v]){
            if(ret[nv] != -1 || nv == 0) continue;
            ret[nv] = v;
            st.push(nv);
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> a(n-1), b(n-1);
    rep(i, n-1){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];

        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<int> parent = rooted_tree(g);

    int q;
    cin >> q;

    vector<ll> res(n, 0);
    while(q--){
        int t, e, x;
        cin >> t >> e >> x;
        --e;

        // a is parent
        if(parent[b[e]] == a[e]){
            if(t == 1){
                res[0] += x;
                res[b[e]] -= x;
            }
            else{
                res[b[e]] += x;
            }
        }
        // b is parent
        else{
            if(t == 1){
                res[a[e]] += x;
            }
            else{
                res[0] += x;
                res[a[e]] -= x;
            }
        }       
    }

    stack<int> st;
    st.push(0);
    vector<bool> seen(n, false);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        seen[v] = true;

        for(int nv: g[v]){
            if(seen[nv]) continue;
            res[nv] += res[v];
            st.push(nv);            
        }
    }

    for(auto e: res) cout << e << endl;

    return 0;
}