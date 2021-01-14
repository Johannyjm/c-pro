#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    vector<vector<int>> order(n, vector<int>(n, -1));
    rep(i, n) rep(j, n-1){
        int a_;
        cin >> a_;
        --a_;
        a[i][j] = a_;
        order[i][a_] = j;
    }

    rep(i, n){
        rep(j, n) cout << order[i][j] << " ";
        cout << endl;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            pq.push({order[i][j]+order[j][i], {i, j}});
        }
    }

    int res = 0;
    vector<int> now(n, 0);
    int cost = 0;
    int i = -1;
    int j = -1;
    while(!pq.empty()){
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        
        cost = p.first;
        i = p.second.first;
        j = p.second.second;

        vector<pair<int, int>> cand;
        cand.push_back({i, j});
        while(!pq.empty() && pq.top().first == cost){
            cand.push_back(pq.top().second);
            pq.pop();
        }

        bool flg = true;
        unordered_map<int, int> used;
        while(1){
            bool flg2 = true;
            cout << cand.size() << endl;
            for(auto p: cand){
                i = p.first;
                j = p.second;
                if(used[i*10000+j]) continue;
                if(now[i]+now[j] <= cost){
                    flg = false;
                    ++now[i];
                    ++now[j];
                    ++used[i*10000+j];
                    flg2 = false;
                }
            }

            if(flg2) break;
        }
        cout << endl;

        if(flg){
            cout << -1 << endl;
            return 0;
        }

        for(auto p: cand){
            if(used[p.first*10000+p.second]) continue;
            pq.push({cost, p});
        }

        ++res;

    }

    cout << res << endl;

    return 0;
}