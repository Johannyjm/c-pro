#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<vector<int>> f(n, vector<int>(10));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j) cin >> f[i][j];
    }

    vector<vector<int>> p(n, vector<int>(11));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 11; ++j) cin >> p[i][j];
    }
    
    vector<int> open(10);
    vector<int> cnt(10);
    int res = -1001001001;
    for(int i = 1; i < (1<<10); ++i){
        open.assign(10, 0);
        for(int j = 0; j < 10; ++j){
            if(i & (1<<j)) open[j] = 1;
        }
        
        cnt.assign(n, 0);
        for(int j = 0; j < n; ++j){
            int c = 0;
            for(int k = 0; k < 10; ++k){
                c += open[k] & f[j][k];
            }
            cnt[j] = c;
        }

        int reward = 0;
        for(int j = 0; j < n; ++j){
            reward += p[j][cnt[j]];
        }

        res = max(res, reward);
    }

    cout << res << endl;
}
