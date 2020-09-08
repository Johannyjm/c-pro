#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    ll K;
    cin >> S >> K;

    char tmp = S[0];
    ll red_num = 0;
    ll red_sum = 0;
    for(int i = 1; i < S.length(); ++i){

        if(tmp == S[i]){
            red_num++;
        }
        else{
            red_sum += (red_num + 1) / 2;
            red_num = 0;
        }
        //cout << S[i] << " " << red_num << " " << red_sum << endl;
        tmp = S[i];
    }
    red_sum += (red_num + 1) / 2;
    red_num = 0;

    if(S[0] == S[S.length() - 1]) {
        
        if(S.length() == 2) {
            cout << K << endl;
        }
        else {
            if(red_sum == 0) cout << K - 1;
            else cout << (red_sum + 1) * K - 2 << endl;
        }
    }
    else cout << red_sum * K << endl;
}