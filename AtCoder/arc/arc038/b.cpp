#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};

int h, w;
vector<vector<char>> c;
bool flg = false;
void dfs(int y, int x, vector<vector<bool>> seen, int turn){
    seen[y][x] = true;
    
    if(c[y][x] == 'o'){
        if(turn == 0) flg = true;
        return;
    }

    int cnt = 0;
    for(int dir = 0; dir < 3; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
        if(seen[ny][nx]) continue;
        if(c[ny][nx] == '#') continue;
        
        ++cnt;
    }

    if(turn==1 && cnt>1) return;
    if(cnt == 0) return;

    for(int dir = 0; dir < 3; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
        if(seen[ny][nx]) continue;
        if(c[ny][nx] == '#') continue;
        
        dfs(ny, nx, seen, 1-turn);
    }
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    
    vector<string> s(h);
    for(int i = 0; i < h; ++i) cin >> s[i];

    c.resize(h, vector<char>(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(i==h-1 && j==w-1) c[i][j] = 'o';
            else if(i==h-1 && j!=w-1 && s[i][j+1]=='#') c[i][j] = 'o';
            else if(j==w-1 && i!=h-1 && s[i+1][j]=='#') c[i][j] = 'o';
            else if(i!=h-1 && j!=w-1){
                if(s[i][j+1]=='#' && s[i+1][j]=='#' && s[i+1][j+1]=='#') c[i][j] = 'o';
                else c[i][j] = s[i][j];
            }
            else c[i][j] = s[i][j];
        }
    }

    
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    
    dfs(0, 0, seen, 0);
    if(flg) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}
