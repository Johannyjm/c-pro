#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 1<<30;
typedef pair<int,int> P;
typedef pair<int,P> P1;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int h,w,t,sx,sy,gx,gy;
int dp[20][1<<19],d[20][20];
char f[305][305];
vector<P> v;
queue<P> q;
bool used[305][305];

int bfs(int sx,int sy,int gx,int gy){
    rep(i,h) rep(j,w) used[i][j] = 0;
    while(!q.empty()) q.pop();
    q.push(P(sx,sy));
    used[sx][sy] = 1;
    int dist[305][305]={};
    while(!q.empty()){
        P p = q.front(); q.pop();
        if(p == P(gx,gy)) return dist[gx][gy];
        rep(i,4){
            int nx = p.first+dx[i],ny = p.second+dy[i];
            if(nx>=0 && nx<h && ny>=0 && ny<w && !used[nx][ny] && f[nx][ny]!='#'){
                dist[nx][ny] = dist[p.first][p.second]+1;
                used[nx][ny] = 1;
                q.push(P(nx,ny));
            }
        }
    }
    return INF;
}

int main(){
    cin>>h>>w>>t;
    rep(i,h) rep(j,w){
        cin>>f[i][j];
        if(f[i][j]=='S') sx=i,sy=j;
        if(f[i][j]=='G') gx=i,gy=j;
        if(f[i][j]=='o') v.push_back(P(i,j));
    }
    v.push_back(P(sx,sy));
    v.push_back(P(gx,gy));
    int n = v.size();
    rep(i,n) rep(j,n) d[i][j] = bfs(v[i].first,v[i].second,v[j].first,v[j].second);
    rep(i,n) rep(j,1<<n) dp[i][j] = INF;
    dp[n-2][1<<(n-2)] = 0;
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i>>j&1){
                for(int k=0;k<n;k++){
                    if(!(i>>k&1)){
                        dp[k][i|(1<<k)] = min(dp[k][i|(1<<k)], dp[j][i]+d[j][k]);
                    }
                }
            }
        }
    }
    int res = -1;
    for(int i=0;i<(1<<n);i++){
        if(dp[n-1][i]<=t) res = max(res, __builtin_popcount(i)-2);
    }
    cout<<res<<endl;
    return 0;
}
