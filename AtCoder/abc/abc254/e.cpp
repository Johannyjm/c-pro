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

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;

        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q;
    cin >> q;

    while(q--){
        int x, k;
        cin >> x >> k;
        
        int res = x;
        --x;

        queue<int> q;
        q.push(x);

        unordered_map<int, int> dist;
        bool flg = false;
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(nv == x) continue;
                if(dist[nv] != 0) continue;

                dist[nv] = dist[v] + 1;
                q.push(nv);

                if(dist[nv] <= k) res += nv+1;
                else{
                    flg = true;
                    break;
                }

            }

            if(flg) break;
        }

        cout << res << endl;
    }

    // while(q--){
    //     int x, k;
    //     cin >> x >> k;

    //     int res = x;
    //     --x;

    //     if(k > 0){
    //         unordered_set<int> st;
    //         int v = x;
    //         st.insert(v);
    //         for(auto nv: g[v]){
    //             if(st.count(nv)) continue;
    //             res += nv+1;
    //             st.insert(nv);

    //             if(k > 1){
    //                 for(auto nnv: g[nv]){
    //                     if(st.count(nnv)) continue;
    //                     res += nnv+1;
    //                     st.insert(nnv);

    //                     if(k > 2){
    //                         for(auto nnnv: g[nnv]){
    //                             if(st.count(nnnv)) continue;
    //                             res += nnnv+1;
    //                             st.insert(nnnv);
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     cout << res << endl;
    // }
    
    // const int INF = 1001001001;
    // vector<int> dist(n);
    // while(q--){
    //     int x, k;
    //     cin >> x >> k;

    //     --x;
    //     queue<int> q;
    //     q.push(x);

    //     dist.assign(n, INF);
    //     dist[x] = 0;

    //     int res = x+1;
    //     while(!q.empty()){
    //         int v = q.front();
    //         q.pop();

    //         bool flg = false;

    //         for(auto nv: g[v]){
    //             if(dist[nv] != INF) continue;

    //             dist[nv] = dist[v] + 1;
    //             q.push(nv);

    //             if(dist[nv] <= k) res += nv+1;
    //             else{
    //                 flg = true;
    //                 break;
    //             }
    //         }

    //         if(flg) break;
    //     }

    //     cout << res << endl;


    // }

    return 0;
}