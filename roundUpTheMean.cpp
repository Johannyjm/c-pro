#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int res = (a + b) / 2;

    if((a + b) % 2 == 1){
        res++;
    }
    cout << res << endl;
}