#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int c[3][3] = {{0}};
    int a[3] = {0}, b[3] = {0};

    for(int i = 0; i < 3; ++i){

        for(int j = 0; j < 3; ++j){
            cin >> c[i][j];

            if(i == 0) b[j] = c[i][j];
            if(i == 1 and j == 0) a[i] = c[i][j] - b[j];
            if(i == 2 and j == 0) a[i] = c[i][j] - b[j];

        }
    }

    bool flg = true;

    for(int i = 0; i < 3; ++i){

        for(int j = 0; j < 3; ++j){

            if(c[i][j] == a[i] + b[j]) flg = flg and true;
            else flg = false;
        }
    }

    // for(int i = 0; i < 3; ++i) cout << a[i];
    // cout << endl;
    // for(int i = 0; i < 3; ++i) cout << b[i];
    // cout << endl;


    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;


}