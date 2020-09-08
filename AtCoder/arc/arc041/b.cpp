#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; ++i) cin >> s[i];
    vector<vector<int>> b(h, vector<int>(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) b[i][j] = s[i][j] - '0';
    }

    vector<vector<int>> res(h, vector<int>(w, 0));
    for(int k = 0; k < min(h, w)/2; ++k){
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(!(i==k || i==h-k-1) && !(j==k || j==w-k-1)) continue;
                if(b[i][j] != 0){
                    int ty, tx;
                    if(i==k){
                        ty = i+1;
                        tx = j;
                    }
                    if(i==h-k-1){
                        ty = i-1;
                        tx = j;
                    }
                    if(j==k){
                        ty = i;
                        tx = j+1;
                    }
                    if(j==w-k-1){
                        ty = i;
                        tx = j-1;
                    }
                    
                    int val = b[i][j];
                    res[ty][tx] = val;
                    b[ty+1][tx] -= val;
                    b[ty-1][tx] -= val;
                    b[ty][tx+1] -= val;
                    b[ty][tx-1] -= val;
                }
            }
        }
    }


    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) cout << res[i][j];
        cout << endl;
    }

    return 0;

}
