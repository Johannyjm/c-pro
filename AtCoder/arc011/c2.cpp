#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string fi, la;
    cin >> fi >> la;
    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        if(str == fi || str == la) continue;

        s.push_back(str);
    }

    int cnt = 0;
    for(int i = 0; i < fi.size(); ++i){
        if(fi[i] != la[i]) ++cnt;
    }
    if(cnt <= 1){
        cout << 0 << endl;
        cout << fi << endl;
        cout << la << endl;
        return 0;
    }

    s.push_back(fi);
    s.push_back(la);
    n = s.size();
    int m = fi.size();
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            cnt = 0;
            for(int k = 0; k < m; ++k){
                if(s[i][k] != s[j][k]) ++cnt;
            }
            if(cnt == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    queue<int> q;
    q.push(n-1);
    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[n-1] = 0;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    if(dist[n-2] == INF){
        cout << -1 << endl;
        return 0;
    }

    vector<string> res;
    int now = n-2;
    res.push_back(s[now]);
    while(now != n-1){
        for(int nxt: g[now]){
            if(dist[nxt] == dist[now]-1){
                now = nxt;
                res.push_back(s[now]);
                break;
            }
        }
    }

    cout << res.size()-2 << endl;
    for(string elem: res) cout << elem << endl;

}

