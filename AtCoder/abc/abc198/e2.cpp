#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<int>> col(110000);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        col[c[i]].push_back(i);
    }

    vector<vector<int>> g(n*2);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    const int INF = 1001001001;
    vector<int> dist1(n, INF);
    dist1[0] = 0;

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(dist1[nv] != INF) continue;

            dist1[nv] = dist1[v] + 1;
            q.push(nv);
        }
    }

    int ptr = 0;
    for(int i = 0; i < 110000; ++i){
        if(col[i].size() < 2) continue;
        
        for(auto v: col[i]){
            g[n+ptr].push_back(v);
            g[v].push_back(n+ptr);
        }
        ++ptr;
    }

    vector<int> dist2(n*2, INF);
    dist2[0] = 0;
    deque<int> dq;
    dq.push_back(0);

    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();

        for(auto nv: g[v]){
            if(dist2[nv] != INF) continue;

            if(nv >= n || v >= n){
                dist2[nv] = dist2[v];
                dq.push_front(nv);
            }
            else{
                dist2[nv] = dist2[v] + 1;
                dq.push_back(nv);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(dist1[i] == dist2[i]) cout << i+1 << "\n";
    }



    return 0;
}
