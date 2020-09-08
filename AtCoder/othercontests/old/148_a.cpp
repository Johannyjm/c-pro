#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;

    if(a == 1){
        if(b == 2){
            cout << 3 << endl;
            return 0;
        }
        if(b == 3){
            cout << 2 << endl;
            return 0;
        }

    }
    if(a == 2){
        if(b == 1){
            cout << 3 << endl;
            return 0;
        }
        if(b == 3){
            cout << 1 << endl;
            return 0;
        }
    }
    if(a == 3){
        if(b == 1){
            cout << 2 << endl;
            return 0;
        }
        if(b == 2){
            cout << 3 << endl;
            return 0;
        }
    }
}