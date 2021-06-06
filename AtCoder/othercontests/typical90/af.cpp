#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> a[i][j];
    int m;
    cin >> m;
    vector<vector<bool>> ng(n, vector<bool>(n, false));
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        ng[x][y] = true;
        ng[y][x] = true;
    }


    int res = 1001001001;
    vector<int> range(n);
    for(int i = 0; i < n; ++i) range[i] = i;

    do{
        bool valid = true;
        int sm = 0;
        for(int i = 0; i < n; ++i){
            if(i < n-1){
                if(ng[range[i]][range[i+1]]) valid = false;
            }
            sm += a[range[i]][i];
        }

        if(valid) res = min(res, sm);

    } while(next_permutation(range.begin(), range.end()));

    if(res == 1001001001) res = -1;
    cout << res << endl;
    

    return 0;
}
