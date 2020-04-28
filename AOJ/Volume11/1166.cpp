#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const int dwi[] = {1, 2, 1, 0};
const int dwj[] = {1, 0, 0, 0};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){

        int w, h;
        cin >> w >> h;

        if(w == 0) break;

        vector<vector<int>> wall(2*h+1, vector<int>(w+1, 2));
        rep1(i, 2*h){
            if(i%2) rep1(j, w) cin >> wall[i][j];
            else rep(j, w) cin >> wall[i][j];
        }

        const int INF = 1001001001;
        vector<vector<int>> dist(h, vector<int>(w, INF));
        dist[0][0] = 0;
        queue<pair<int, int>> q;
        q.push((make_pair(0, 0)));

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            rep(dir, 4){
                int ni = i + di[dir];
                int nj = j + dj[dir];
                int wi = 2*i + dwi[dir];
                int wj = j + dwj[dir];

                if(wi<0 || wi>=2*h+1 || wj<0 || wj>=w+1) continue;
                if(ni<0 || ni>=h || nj<0|| nj>=w) continue;
                if(wall[wi][wj] != 0) continue;
                if(dist[ni][nj] != INF) continue;

                dist[ni][nj] = dist[i][j] + 1;
                q.push(make_pair(ni, nj));
            }
        }

        if(dist[h-1][w-1] == INF) cout << 0 << endl;
        else cout << dist[h-1][w-1]+1 <<endl;
    }

    return 0;
}