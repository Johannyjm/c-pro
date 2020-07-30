#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) cin >> s[i][j];
    
    const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    vector<vector<char>> whiten = s;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(s[i][j] == '#') continue;
            
            for(int dir = 0; dir < 8; ++dir){
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>w) continue;
                if(s[ny][nx] == '#') whiten[ny][nx] = '.';
            }

        }
    }

    vector<vector<char>> blacken = whiten;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(whiten[i][j] == '.') continue;
            
            for(int dir = 0; dir < 8; ++dir){
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>w) continue;
                if(whiten[ny][nx] == '.') blacken[ny][nx] = '#';
            }

        }
    }

    
    for(int i = 0; i < h; ++i){
        for(int j = 0 ; j < w; ++j){
            if(s[i][j] != blacken[i][j]){
                cout << "impossible" << endl;
                return 0;
            }
        }
    }


    cout << "possible" << endl;
    for(int i = 0; i < h; ++i){
        for(int j = 0 ; j < w; ++j){
            cout << whiten[i][j];
        }
        cout << endl;
    }
    return 0;

}
