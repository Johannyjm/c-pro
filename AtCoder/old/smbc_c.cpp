#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;

    for (int i = 1; i <= 1000; ++ i){

        if(100 * i <= x && x <= 105 * i){
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

}