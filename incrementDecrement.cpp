#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string S;
    cin >> S;

    int x = 0;
    int res = 0;

    for (int i = 0; i < N; ++i){
        
        if(S[i] == 'I') x++;
        else x--;

        if(x > res) res = x;
    }

    cout << res << endl;
}