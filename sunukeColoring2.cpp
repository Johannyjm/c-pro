#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int W, H, N;
    cin >> W >> H >> N;

    int X[W] = {0};
    int Y[H] = {0};

    for(int i = 0; i < N; ++i){
        int x, y, a;
        cin >> x >> y >> a;

        if(a == 1){

            for(int j = x - 1; j > -1; --j) X[j] += 1;
        }

        if(a == 2){

            for(int j = x; j < W; ++j) X[j] += 1;
        }

        if(a == 3){

            for(int j = y - 1; j > -1; --j) Y[j] += 1;
        }

        if(a == 4){

            for(int j = y; j < H; ++j) Y[j] += 1;
        }
    }

    int w = 0;
    int h = 0;

    for(int i = 0; i < W; ++i){

        if(X[i] == 0) ++w;
    }

    for(int i = 0; i < H; ++i){

        if(Y[i] == 0) ++h;
    }

    cout << w * h << endl;
}