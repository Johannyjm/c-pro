#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    int res = 0;
    char temp = S[0];
    
    for(int i = 1; i < N; ++i){

        if(S[i] != temp){
            res += 1;
            temp = S[i];
        }
    }
    cout << res << endl;
}