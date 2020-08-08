#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> colors;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < a[i]; ++j) colors.push_back(i+1);
    }
    
    vector<vector<int>> res(h, vector<int>(w));
    int ptr = 0;
    for(int i = 0; i < h; ++i){
        if(i%2 == 0){
            for(int j = 0; j < w; ++j){
                res[i][j] = colors[ptr];
                ++ptr;
            }
        }
        else{
            for(int j = w-1; j >= 0; --j){
                res[i][j] = colors[ptr];
                ++ptr;
            }
        }
    }

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w-1; ++j) cout << res[i][j] << " ";
        cout << res[i].back() << endl;
    }

    return 0;
}
