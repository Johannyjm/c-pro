#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    vector<int> top, bottom;
    for(int i = 0; i < q; ++i){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            top.push_back(x);
        }
        if(t == 2){
            bottom.push_back(x);
        }
        if(t == 3){
            --x;
            int n = top.size();
            int m = bottom.size();
            
            if(x < n) cout << top[n-1-x] << "\n";
            else{
                x -= n;
                cout << bottom[x] << "\n";
            }
        }
    }

    return 0;
}
