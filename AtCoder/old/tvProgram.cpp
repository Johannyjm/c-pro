#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int D, Sh, Sm, Th, Tm;
    cin >> D >> Sh >> Sm >> Th >> Tm;
    bool flg = false;
    
    if(D == 6 or D == 7){
        
        if(7 <= Sh and (Th < 22 or (Th == 22 and Tm == 0))){
            flg = true;
        }
    } else {
        if(19 <= Sh and (Th < 22 or (Th == 22 and Tm == 0))){
            flg = true;
        }
    }
    
    if(flg) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}