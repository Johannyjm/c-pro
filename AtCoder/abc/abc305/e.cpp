#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int, int>> hp(k);
    rep(i, k){
        int p, h;
        cin >> p >> h;
        --p;
        hp[i] = {h+1, p};
    }

    sort(hp.begin(), hp.end(), greater<pair<int, int>>());

    vector<int> looked(n, 0);
    rep(i, k){
        auto [h, p] = hp[i];

        if(looked[p] >= h) continue;

        looked[p] = h;

        queue<int> q;
        q.push(p);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                int nh = looked[v] - 1;
                if(looked[nv] >= nh) continue;

                looked[nv] = nh;
                q.push(nv);
            }
        }
    }

    int res_n = 0;
    vector<int> res;
    rep(v, n){
        if(looked[v] > 0){
            ++res_n;
            res.push_back(v+1);
        }
    }
    
    cout << res_n << endl;
    for(auto elem: res){
        cout << elem << " ";
    }
    cout << endl;



    return 0;
}