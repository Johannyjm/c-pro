#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    int d_sum = 0;
    rep(i, n){
        cin >> d[i];
        d_sum += d[i];
    }

    vector<vector<int>> g(n);

    dsu uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        
        uf.merge(a, b);

        --d[a];
        --d[b];
    }

    int n_connected = uf.groups().size();

    if(n-m-1 < n_connected-1){
        cout << -1 << endl;
        return 0;
    }

    if(d_sum != 2*(n-1)){
        cout << -1 << endl;
        return 0;
    }

    priority_queue<pair<int, int>> sm_d;
    for(auto group: uf.groups()){
        int lv = uf.leader(group[0]);
        int sm = 0;
        for(auto v: group){
            sm += d[v];
        }
        sm_d.push({sm, lv});
    }

    while(!sm_d.empty()){
        auto [s1, v1] = sm_d.top();
        sm_d.pop();
        if(sm_d.empty()){
            cout << -1 << endl;
            return 0;
        }

        auto [s2, v2] = sm_d.top();
        sm_d.pop();

        if(s1 == 0 && s2 == 0) break;
        if((s1==0&&s2==1) || (s1==1&&s2==0)){
            cout << -1 << endl;
            return 0;
        }

        cout << v1+1 << " " << v2+1 << "\n";

        --s1;
        --s2;
        uf.merge(v1, v2);
        --d[v1];
        --d[v2];
        // v1 = uf.leader(v1);
        vector<int> g_i;
        for(auto group: uf.groups()){
            if(uf.same(group[0], v1)){
                g_i = group;
                break;
            }
        }
        for(auto v: g_i){
            if(d[v] != 0){
                v1 = v;
                break;
            }
        }
        s1 = s1 + s2;

        sm_d.push({s1, v1});
    }

    return 0;
}