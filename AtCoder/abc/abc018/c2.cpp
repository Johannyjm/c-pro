#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c, k;
    cin >> r >> c >> k;
    vector<string> s(r);
    for(int i = 0 ; i < r; ++i) cin >> s[i];

    vector<int> y, x;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(s[i][j] == 'x'){
                y.push_back(i);
                x.push_back(j);
            }
        }
    }

    vector<vector<int>> islegal(r, vector<int>(c, 0));
    for(int i = k-1; i < r-k+1; ++i){
        for(int j = k-1; j < c-k+1; ++j) islegal[i][j] = 1;
    }

    int m = y.size();
    for(int i = 0; i < m; ++i){
        int cy = y[i];
        int cx = x[i];
        for(int ny = cy-(k-1); ny <= cy+(k-1); ++ny){
            for(int nx = cx-(k-1); nx <= cx+(k-1); ++nx){
                if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
                if(abs(cy-ny) + abs(cx-nx) > k-1) continue;
                islegal[ny][nx] = 0;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j) res += islegal[i][j];
    }

    cout << res << endl;

    return 0;
}
