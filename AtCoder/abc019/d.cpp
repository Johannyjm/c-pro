#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    int v = 0;
    int mx = 0;
    for(int i = 2; i <= n; ++i){
        int dist;
        cout << "? " << 1 << " " << i  << endl;
        cin >> dist;
        if(dist > mx){
            mx = dist;
            v = i;
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(i == v) continue;
        int dist;
        cout << "? " << v << " " << i << endl;
        cin >> dist;

        res = max(res, dist);
    }

    cout << "! " << res << endl;
    
    return 0;
}
