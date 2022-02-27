#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];

    int cnt = 1001001001;

    // yoko
    for(int i = 0; i < n; ++i){
        
        int sm = 0;
        for(int j = 0; j < 6; ++j){
            if(s[i][j] == '.') ++sm;
        }

        int sm_cand = sm;

        for(int j = 6; j < n; ++j){
            if(s[i][j] == '.') ++sm;
            if(s[i][j-6] == '.') --sm;
            sm_cand = min(sm_cand, sm);
        }
        
        cnt = min(cnt, sm_cand);
    }

    // tate
    for(int j = 0; j < n; ++j){
        
        int sm = 0;
        for(int i = 0; i < 6; ++i){
            if(s[i][j] == '.') ++sm;
        }

        int sm_cand = sm;

        for(int i = 6; i < n; ++i){
            if(s[i][j] == '.') ++sm;
            if(s[i-6][j] == '.') --sm;
            sm_cand = min(sm_cand, sm);
        }
        
        cnt = min(cnt, sm_cand);
    }

    // naname
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i+5 >= n || j+5 >= n) continue;

            int sm_cand = 1001001001;
            int sm = 0;
            for(int k = 0; k < 6; ++k){
                if(s[i+k][j+k] == '.') ++sm;
            }
            sm_cand = min(sm_cand, sm);

            sm = 0;
            for(int k = 0; k < 6; ++k){
                if(s[i+k][j+5-k] == '.') ++sm;
            }
            sm_cand = min(sm_cand, sm);

            cnt = min(cnt, sm_cand);
        }
    }

    if(cnt <= 2) puts("Yes");
    else puts("No");


    return 0;
}
