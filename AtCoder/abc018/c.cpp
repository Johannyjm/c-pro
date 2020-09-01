#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k;
vector<string> grid;
bool legal(int y, int x){
    int r = k-1;
    for(int i = y-r; i <= y+r; ++i){
        for(int j = x-r; j <= x+r; ++j){
            if(abs(y-i) + abs(x-j) > r) continue;
            if(grid[i][j] == 'x') return false;
        }
    }
    
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c >> k;

    grid.resize(r);
    for(int i = 0; i < r; ++i) cin >> grid[i];
    
    int res = 0;
    for(int i = k-1; i < r-k+1; ++i){
        for(int j = k-1; j < c-k+1; ++j){
            if(legal(i, j)) ++res;
        }
    }

    cout << res << endl;

    return 0;
}
