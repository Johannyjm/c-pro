#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    int mn = 110000;
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        
        mn = min(mn, m);
        x -= m;
    }

    int res = n + x/mn;
    
    cout << res << endl;

    return 0;
}
