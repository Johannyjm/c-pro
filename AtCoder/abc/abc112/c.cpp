#include <iostream>
#include <vector>

using namespace std;

int calc_height(int h, int cx, int cy, int x, int y){
    return max(h-abs(x-cx)-abs(y-cy), 0);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i];
    int ptr = 0;
    while(h[ptr] == 0) ++ptr;

    for(int cx = ptr; cx <= 100; ++cx){
        for(int cy = ptr; cy <= 100; ++cy){
            int h_cand = h[ptr] + abs(cx-x[ptr]) + abs(cy-y[ptr]);
            
            bool flg = true;
            for(int i = 0; i < n; ++i){
                if(calc_height(h_cand, cx, cy, x[i], y[i]) != h[i]){
                    flg = false;
                    break;
                }
            }


            if(flg){
                cout << cx << " " << cy << " " << h_cand << endl;
                return 0;
            }
        }
    }



}
