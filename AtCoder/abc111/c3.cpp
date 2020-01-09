#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int even_buc[100001] = {0};
    int odd_buc[100001] = {0};

    rep(i, n){
        int v;
        cin >> v;

        if(i%2) ++even_buc[v];
        else ++odd_buc[v];
    }

    int max_even = -1;
    int max_e_num = -1;
    int max_odd = -1;
    int max_o_num = -1;

    rep(i, 100001){
        if(even_buc[i] > max_even){
            max_even = even_buc[i];
            max_e_num = i;
        }
        if(odd_buc[i] > max_odd){
            max_odd = odd_buc[i];
            max_o_num = i;
        }
    }

    sort(even_buc, even_buc+100001, greater<int>());
    sort(odd_buc, odd_buc+100001, greater<int>());

    if(max_e_num == max_o_num){
        if(max_even == max_odd){
            int e_res = max_even;
            int o_res = max_odd;

            for (int i = 2; i < 100001; ++i){
                if(even_buc[i] == 0) break;
                e_res += even_buc[i];
            }
            for (int i = 1; i < 100001; ++i){
                if(odd_buc[i] == 0) break;
                e_res += odd_buc[i];
            }
            
            for (int i = 2; i < 100001; ++i){
                if(odd_buc[i] == 0) break;
                o_res += odd_buc[i];
            }
            for (int i = 1; i < 100001; ++i){
                if(even_buc[i] == 0) break;
                o_res += even_buc[i];
            }
            
            cout << min(e_res, o_res) << endl;
            return 0;

        }
        else{
            if(max_even>max_odd) odd_buc[1] = odd_buc[0];
            else even_buc[1] = even_buc[0];
        }
    }

    if(even_buc[1] == 0 && odd_buc[1] == 0) cout << 0 << endl;
    else {
        int res = 0;
        if(even_buc[1]){
            for (int i = 1; i < 100001; ++i) {
                if(even_buc[i] == 0) break;
                res += even_buc[i];
            }
        }
        if(odd_buc[1]){
            for (int i = 1; i < 100001; ++i) {
                if(odd_buc[i] == 0) break;
                res += odd_buc[i];
            }
        }

        cout << res << endl;
    }
}