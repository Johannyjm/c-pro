#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    bool flg = true;
    string tmp;

    cin >> S;

    for(int i = 0; i < S.length(); ++i) {
        tmp = S[i];
        flg = tmp == "t";
        cout << flg << endl;

    }
}