#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<vector<int>> cnt(h, vector<int>(w, -1));
    rep(i, h) rep(j, w){
        if(a[i][j]=='#') cnt[i][j] = 0;
    }

    int now = 0;
    while(1){
        bool flg = true;

        rep(i, h) rep(j, w){
            if(cnt[i][j] != now) continue;
            rep(dir, 4){
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(cnt[ny][nx]!=-1) continue;

                cnt[ny][nx] = now+1;
                flg = false;
            }
        }
        
        if(flg) break;
        ++now;
    }

    cout << now << endl;

    return 0;
}