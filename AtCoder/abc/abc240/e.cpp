#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> cnt_leaf, isleaf;
vector<bool> seen;

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

int dfs(int v){
    seen[v] = true;

    if(isleaf[v] == 1) return 1;

    int cnt = 0;
    for(auto nv: g[v]){
        if(seen[nv]) continue;

        cnt += dfs(nv);
    }

    cnt_leaf[v] = cnt;

    return cnt;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    g.resize(n);
    rep(_, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> p = rooted_tree(g);
    
    cnt_leaf.resize(n, 1);
    isleaf.resize(n, 1);
    cnt_leaf[0] = 0;
    rep1(i, n){
        cnt_leaf[p[i]] = 0;
    }

    isleaf = cnt_leaf;
    seen.resize(n, false);
    dfs(0);

    vector<pair<int, int>> res(n);
    res[0] = {1, cnt_leaf.front()};
    queue<int> q;
    q.push(0);
    seen.assign(n, false);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        seen[v] = true;

        int l = res[v].first;
        for(auto nv: g[v]){
            if(seen[nv]) continue;
            q.push(nv);

            res[nv] = {l, l+cnt_leaf[nv] - 1};
            l += cnt_leaf[nv];            
        }
    }

    rep(i, n){
        cout << res[i].first << " " << res[i].second << "\n";
    }

    return 0;
}