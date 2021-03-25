#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    cin >> x;

    for(char c: x){
        if(c != '.') cout << c;
        else break;
    }
    cout << endl;

    return 0;
}
