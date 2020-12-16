#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    dsu uf(h*w);
    vector<vector<ll>> cnts(h, vector<ll>(w, -1));
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(h, vector<bool>(w, false));

    rep(i, h) rep(j, w){
        if(s[i][j] != '#') continue;

        if(uf.size(w*i+j) != 1){
            int l = uf.leader(w*i+j);
            cnts[i][j] = cnts[l/w][l%w];
            continue;
        }

        bool legal = false;
        rep(dir, 4){
            int ny = i + dy[dir];
            int nx = j + dx[dir];
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '.') legal = true;
        }
        if(!legal) continue;

        ll cnt = 0;
        q.push({i, j});
        seen.assign(h, vector<bool>(w, false));
        seen[i][j] = true;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int y = p.first;
            int x = p.second;

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(seen[ny][nx]) continue;
                if(s[y][x]=='#' && s[ny][nx]=='#') continue;
                if(s[y][x]=='.' && s[ny][nx]=='.') continue;

                if(s[ny][nx]=='.') ++cnt;
                if(s[ny][nx]=='#') uf.merge(w*i+j, w*ny+nx);

                seen[ny][nx] = true;
                q.push({ny, nx});
            }
        }

        cnts[i][j] = cnt;
    }

    ll res = 0;
    rep(i, h) rep(j, w){
        if(cnts[i][j] != -1) res += cnts[i][j];
    }

    cout << res << endl;

    return 0;
}