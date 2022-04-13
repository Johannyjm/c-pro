#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<int, int> mpx, mpy;
    for(int i = 0; i < 3; ++i){
        int x, y;
        cin >> x >> y;

        ++mpx[x];
        ++mpy[y];
    }

    for(auto k: mpx){
        if(k.second == 1) cout << k.first << " ";
    }

    for(auto k: mpy){
        if(k.second == 1) cout << k.first << endl;
    }
    
}
