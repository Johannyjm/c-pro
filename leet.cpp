#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string S;
    cin >> S;
    bool res = false;

    for(int i = 0; i < S.length(); ++i){
        char c = S[i];
        res = res or isdigit(c);
    } 
    if(res) cout << "leet" << endl;
    else cout << "Noleet" << endl;
    return 0;
}