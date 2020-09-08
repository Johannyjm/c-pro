#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> si(n);
    for(int i = 0; i < n; ++i){
        if(s[i] == 'o') si[i] = 1;
        else si[i] = 0;
    }

    int res = n+1;
    vector<int> shifted(n);
    for(int i = 0; i < (1<<n); ++i){
        int cnt = 0;
        shifted.assign(n, 0);
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                for(int k = 0; k < n; ++k){
                    if(k-j < 0) shifted[k] += si[k-j+n];
                    else shifted[k] += si[k-j];
                }

                ++cnt;
            }
        }
        
        bool flg = true;
        for(int j = 0; j < n; ++j){
            if(shifted[j] == 0) flg = false;
        }

        if(flg) res = min(res, cnt);
    }

    cout << res << endl;

    return 0;
}
