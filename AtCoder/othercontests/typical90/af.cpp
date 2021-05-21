#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[10][10];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cin >> a[i][j];
    }
    
    int m;
    cin >> m;
    int ng[10][10] = {};
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        ng[x][y] = 1;
        ng[y][x] = 1;
    }

    vector<int> range(n);
    for(int i = 0; i < n; ++i) range[i] = i;

    const int INF = 1001001001;
    int res = INF;
    do{
        int sm = 0;
        bool invalid = false;
        for(int i = 0; i < n; ++i){
            int from = range[i];
            if(i < n-1){
                int to = range[i+1];
                if(ng[from][to]) invalid = true;
            }
            sm += a[i][from];
        }
        
        if(!invalid) res = min(res, sm);

    } while(next_permutation(range.begin(), range.end()));

    if(res == INF) res = -1;
    cout << res << endl;

    return 0;
}
