#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> g(h);
    for(int i = 0; i < h; ++i) cin >> g[i];
    
    vector<int> c_can(w, 0), r_can(h, 0);
    // c_can[0] = c_can[w-1] = r_can[0] = r_can[h-1] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({h-1, 0});
    q.push({0, w-1});
    q.push({h-1, w-1});

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        if(r_can[y]==1 && c_can[x]==1) continue;

        r_can[y] = 1;
        c_can[x] = 1;
        for(int i = 0; i < h; ++i){
            if(g[i][x] == '#') q.push({i, x});
        }
        for(int j = 0; j < w; ++j){
            if(g[y][j] == '#') q.push({y, j});
        }
    }

    // for(int _ = 0; _ < h+w; ++_){
    //     bool modified = false;
    //     for(int i = 0; i < h; ++i){
    //         for(int j = 0; j < w; ++j){
    //             if(r_can[i]==0 && c_can[j]==0) continue;
    //             if(g[i][j] != '#') continue;

    //             r_can[i] = 1;
    //             c_can[j] = 1;
    //             modified = true;
    //         }
    //     }
    //     if(!modified) break;
    // }

    //for(auto e: r_can) cout << e << " ";
    //cout << endl;
    //for(auto e: c_can) cout << e << " ";
    //cout << endl;

    int res1 = 0;
    int res2 = 0;
    for(int i = 0; i < h; ++i){
        if(r_can[i] == 0) ++res1;
    }
    for(int j = 0; j < w; ++j){
        if(c_can[j] == 0) ++res2;
    }

    cout << min(res1, res2) << endl;

    return 0;
}
