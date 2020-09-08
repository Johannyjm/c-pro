#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> isyes(111000, 0);
    int base = 1;
    while(base*(base+1)/2 <= 110000){
        isyes[base*(base+1)/2] = base;
        ++base;
    }

    if(isyes[n] == 0){
        puts("No");
        return 0;
    }

    int len_s = isyes[n];
    int num_s = len_s+1;

    vector<vector<int>> res(num_s, vector<int>(len_s));
    int now = 1;
    rep(i, num_s){
        for(int j = i; j < len_s; ++j){
            res[i][j] = now;
            ++now;
        }
    }

    now = 1;
    rep(j, len_s){
        for(int i = j+1; i < num_s; ++i){
            res[i][j] = now;
            ++now;
        }
    }

    cout << "Yes" << endl;
    cout << num_s << endl;
    rep(r, num_s){
        cout << len_s << " ";
        rep(c, len_s) cout << res[r][c] << " ";
        cout << endl;
    }


    return 0;
}