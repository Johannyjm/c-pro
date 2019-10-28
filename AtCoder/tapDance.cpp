#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    bool flg = true;
    string move;

    cin >> S;

    for(int i = 0; i < S.length(); ++i) {
        move = S[i];
        
        if((i % 2 == 1) && (move == "R")){
            flg = false;
        }
        if((i % 2 == 0) && (move == "L")){
            flg = false;
        }
    }

    if(flg){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}