#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<vector<int>> g;
vector<bool> seen;
vector<int> rooted_tree(){

    vector<int> ret(n);
    ret[0] = -1;

    seen.assign(n, false);
    seen[0] = true;

    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        seen[v] = true;

        for(auto nv: g[v]){
            if(seen[nv]) continue;

            st.push(nv);
            ret[nv] = v;
        }
    }

    return ret;
}


vector<ll> res;
void dfs(int v){
    seen[v] = true;
    for(auto nv: g[v]){
        if(seen[nv]) continue;
        res[nv] += res[v];
        dfs(nv);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<ll> a(n-1), b(n-1);

    g.resize(n);
    rep(i, n-1){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<int> parent = rooted_tree();

    // for(auto e: parent) cout << e << " ";
    // cout << endl;

    int q;
    cin >> q;

    res.resize(n, 0);
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

    seen.assign(n, false);
    dfs(0);

    for(auto e: res) cout << e << endl;

    return 0;
}