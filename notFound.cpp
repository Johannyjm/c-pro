#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int bucket[26] = {0};
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < S.length(); ++i){
        bucket[S[i] - 'a'] += 1;
    }

    for(int i = 0; i < 26; ++i){

        if(bucket[i] == 0){
            cout << alpha[i] << endl;
            return 0;
        }
    }

    cout << "None" << endl;

}