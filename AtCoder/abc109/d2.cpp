#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) cin >> a[i][j];
    }
    
    vector<pair<int, int>> snaked;
    for(int i = 0; i < h; ++i){
        if(i%2 == 0){
            for(int j = 0; j < w; ++j){
                snaked.push_back(make_pair(i+1, j+1));
            }
        }
        else{
            for(int j = w-1; j >= 0; --j){
                snaked.push_back(make_pair(i+1, j+1));
            }
        }
    }

    vector<vector<int>> res;
    pair<int, int> prev = make_pair(-1, -1);
    for(int i = 0; i < snaked.size(); ++i){
        int y = snaked[i].first - 1;
        int x = snaked[i].second - 1;

        if(prev.first == -1){
            if(a[y][x] % 2 == 1){
                prev = make_pair(y+1, x+1);
            }
        }
        else{
            res.push_back({prev.first, prev.second, y+1, x+1});
            if(a[y][x] % 2 == 1) prev = make_pair(-1, -1);
            else prev = make_pair(y+1, x+1);
        }

    }

    cout << res.size() << endl;

    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < 3; ++j) cout << res[i][j] << " ";
        cout << res[i].back() << endl;
    }
}
