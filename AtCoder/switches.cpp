#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int k[m];

    int s[10][10] = {0};
    for (int i = 0; i < m; ++i){
        cin >> k[i];
        for(int j = 0; j < k[i]; ++j){
            cin >> s[i][j];
        }
    }

    int p[m];
    for (int i = 0; i < m; ++i) cin >> p[i];

    int res = 0;
    for (int i = 0; i < 1<<n; ++i){
        int on[n] = {0};

        for (int j = 0; j < n; ++j){

            if(i & (1<<j)){
                on[j] = 1;
            }
        }

        bool flg = true;

        for (int j = 0; j < m; ++j){
            int cnt = 0;
            for(int l = 0; l < k[j]; ++l){
                cnt += on[s[j][l] - 1];
            }
            
            if(cnt%2 != p[j]) flg = false;
        }

        if(flg) res++;
    }
    cout << res << endl;
}