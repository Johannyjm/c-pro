#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int res = 0;
    
    for (int i = 1; i <= b; ++i){
        int available = (i - 1) * (a - 1) + a;
        if(available >= b){
            res = i;
            break;
        }
    }
    cout << res << endl;
}