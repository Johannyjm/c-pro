#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string directions = "RRRRLLLL";
    int n = directions.size();
    int res = 0;
    int sm = 0;
    bool flg = false;
    for(int i = 0; i < n; ++i){
        
        if(!flg){
            if(directions[i] == 'R'){
                flg = true;
            }
        }
        else{
            if(directions[i] == 'R'){
                ++sm;
            }
            if(directions[i] == 'S'){
                res += 1 + sm;
                sm = 0;
                flg = false;
            }
            if(directions[i] == 'L'){
                res += 2 + 2*sm;
                sm = 0;
                flg = false;
            }
        }
    }

    sm = 0;
    flg = false;
    for(int i = n-1; i >= 0; --i){
        
        if(!flg){
            if(directions[i] == 'L'){
                flg = true;
            }
        }
        else{
            if(directions[i] == 'L'){
                ++sm;
            }
            if(directions[i] == 'S'){
                res += 1 + sm;
                sm = 0;
                flg = false;
            }
            if(directions[i] == 'R'){
                res += 2*sm;
                sm = 0;
                flg = false;
            }
        }
    }

    cout << res << endl;
    

    return 0;
}