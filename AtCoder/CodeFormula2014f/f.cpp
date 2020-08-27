#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio (false);

    int w = 1500;
    int h = 1500;

    vector<pair<int, int>> res;
    int now = 200;
    int r_prev = 0;
    int d_prev = 0;
    while(true){
        int r = r_prev + d_prev + now/2;
        if(r + now/2 > h) break;
        int c = now/2;
        d_prev = now;

        while(c + now/2 < w){
            res.push_back({r, c});
            c += now/2;

            if(c + now/2 + now-2 > 1500) break;
            now -= 2;
            c += now/2;
        }
        
        r_prev = r;
        
        if(res.size() == 100) break;
    }
    
    int n = res.size();
    for(int i = n-1; i >= 0; --i) cout << n-i << ": " << res[i].first << " " << res[i].second << endl;

    return 0;
}
