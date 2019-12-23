#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int h;

    int table[n][100] = {0};
    for(int i = 0; i < n; ++i){
        cin >> h;
        for(int j = 0; j < 100; ++j){
            if(0<=j && j<h) table[i][j] = 1;
            else table[i][j] = 0;
        }
    }

    int res = 0;
    bool flg = false;
    for (int i = 0; i < 100; ++i){
        for (int j = 0; j < n; ++j){

            if(table[j][i] == 1) flg = true;
            else{
                if(flg) res++;
                flg = false;
            }
        }
        if(flg) res++;
        flg = false;
    }

    cout << res << endl;


}