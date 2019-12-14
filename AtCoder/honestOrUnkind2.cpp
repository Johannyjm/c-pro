#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n];
    int xy[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) xy[i][j] = -1;
    }

    for(int i = 0; i < n; ++i){
        cin >> a[i];

        for(int j = 0; j < a[i]; ++j) {
            int tmp;
            cin >> tmp;
            cin >> xy[i][tmp-1];
        }
    }

    int res = 0;

    for(int i = 0; i < 1<<n; ++i){
        int honest[n] = {0}; 
        int d = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                honest[j] = 1;
                d++;
            }
        }

        bool flg = true;
        for(int j = 0; j < n; ++j){

            if(!honest[j])continue;

            for(int k = 0; k < n; ++k){
                if(j==k || xy[j][k] == -1) continue;
                if(xy[j][k] ^ honest[k]) flg = false;
            }
   
        }
        if(flg) res = max(res, d);
    }

    cout << res << endl;
}