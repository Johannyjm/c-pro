#include <iostream>
using namespace std;

//double a1[12];

int main(){
    double a1[1232] = {0.0};
    
    a1[0] = 1.0;
    a1[1231] = -0.98723423;
    for(int i = 0; i < 1232; ++i){
        cout << a1[i]*0.3 << " ";
    }

    cout << endl;
}
