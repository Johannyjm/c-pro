#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<pair<int, int>> three;
    map<int, int> exists;
    vector<pair<int, int>> freq(n);
    rep(i, n) freq[i] = make_pair(0, i);
    vector<int> res(n, 0);

    rep(s, n){

        vector<int> dist(n, -1);
        queue<int> que;
        bool b_flg = false;

        dist[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front();
            que.pop();

            for(int nv: G[v]){
                if(dist[nv] != -1) continue;

                dist[nv] = dist[v] + 1;
                
                if(dist[nv]==3 && exists[nv]!=s && exists[s]!=nv){
                    three.push_back(make_pair(s, nv));
                    ++freq[s].first;
                    ++freq[nv].first;
                    exists[nv] = s;
                }
                if(dist[nv]>3){
                    b_flg = true;
                    break;
                }
                que.push(nv);
            }

            if(b_flg) break;
        }
    }

    sort(freq.begin(), freq.end(), greater<pair<int, int>>());

    vector<int> fixed(n, 0);

    rep(i, n/3){
        int idx = freq[i].second;
        res[idx] = 3 * (i+1);
        fixed[idx] = 1;
    }

    int base = 0;
    int current = 0;
    rep(i, three.size()){
        if(res[three[i].first]==0 && res[three[i].second]==0){
            if(base*3+2>n){
                cout << -1 << endl;
                return 0;
            }
            res[three[i].first] = base*3 + 1;
            res[three[i].second] = base*3 + 2;
            ++base;
        }
    }

    base = base*3 + 1;

    rep(i, n){
        if(res[i]==0){
            if(base>n+2){
                cout << -1 << endl;
                return 0;
            }
            res[i] = base;
            ++base;
            if(base%3==0)++base;
        }
    }

    rep(i, n) cout << res[i] << " ";
    cout << endl;
    

    // cout << endl;
    // rep(i, n) cout << freq[i].second << " " << freq[i].first << endl;
    // cout << endl;
    // rep(i, n) cout << res[i] << endl;

    // cout << endl;
    // rep(i, three.size()) cout << three[i].first << " " << three[i].second << endl;
    // cout << endl;
    // cout << endl;
    


    return 0;
}