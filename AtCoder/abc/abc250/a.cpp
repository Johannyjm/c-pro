#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, r, c;
    cin >> h >> w >> r >> c;

    if(h == 1 && w == 1){
        cout << 0 << endl;
        return 0;
    }
    if(h == 1 || w == 1){
        
        if(h == 1){
            if(c == 1 || c == w){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
        else{
            if(r == 1 || r == h){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
        return 0;
        
    }

    if(1 < r && r < h){
        if(1 < c && c < w){
            cout << 4 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
    else{
        if(1 < c && c < w){
            cout << 3 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }

    return 0;
}