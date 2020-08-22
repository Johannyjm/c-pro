#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;
    ll si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    --si;
    --sj;
    --gi;
    --gj;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {si, sj}});
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[si][sj] = 0;
 
    while(!pq.empty()){
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int y = p.second.first;
        int x = p.second.second;

        for(int ni = -2; ni <= 2; ++ni) for(int nj = -2; nj <= 2; ++nj){
            if(ni==0 && nj==0) continue;
            int ny = y + ni;
            int nx = x + nj;

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '#') continue;
            int cost;
            if((ni==0&&nj==1) || (ni==1&&nj==0) || (ni==0&&nj==-1) || (ni==-1&&nj==0)) cost = 0;
            else cost = 1;
 
            if(dist[y][x] + cost < dist[ny][nx]){
                dist[ny][nx] = dist[y][x] + cost;
                pq.push({dist[ny][nx], {ny, nx}});
            }

        }
    }

    if(dist[gi][gj] == INF) cout << -1 << endl;
    else cout << dist[gi][gj] << endl;

    return 0;
}