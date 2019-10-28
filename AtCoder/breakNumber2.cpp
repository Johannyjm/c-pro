#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int num = 1;

    while(true){
        
        if(num > N) break;
        num *= 2;
    }
    cout << num / 2 << endl;
}