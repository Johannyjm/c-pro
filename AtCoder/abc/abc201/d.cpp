#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> a;
int dp[2200][2200];
int rec(int i, int j){
    if(dp[i][j] != 0) return dp[i][j];
    if(i==0 && j==0) return 0;

    int ret;
    if(i > 0){
        // from Takahashi's choice
        if((i + j) % 2 != 0){
            if(a[i][j] == '+'){
                ret = rec(i-1, j) + 1;
            }
            else{
                ret = rec(i-1, j) - 1;
            }
        }
        // from Aoki's choice
        else{
            if(a[i][j] == '+'){
                ret = rec(i-1, j) - 1;
            }
            else{
                ret = rec(i-1, j) + 1;
            }
        }
    }

    if(j > 0){
        if((i + j) % 2 != 0){
            if(a[i][j] == '+'){
//                if(i == 0) ret = -1001001001;
                ret = max(ret, rec(i, j-1) + 1);
            }
            else{
 //               if(i == 0) ret = -1001001001;
                ret = max(ret, rec(i, j-1) - 1);
            }
        }
        else{
            if(a[i][j] == '+'){
//                if(i == 0) ret = 1001001001;
                ret = min(ret, rec(i, j-1) - 1);
            }
            else{
//                if(i == 0) ret = 1001001001;
                ret = min(ret, rec(i, j-1) + 1);
            }
        }
    }
    
    dp[i][j] = ret;

    return ret;
    
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    a.resize(h);
    for(int i = 0; i < h; ++i) cin >> a[i];
    
    int res = rec(h-1, w-1);

    if(res == 0) cout << "Draw";
    if(res > 0) cout << "Takahashi";
    if(res < 0) cout << "Aoki";
    cout << endl;

    return 0;
}

