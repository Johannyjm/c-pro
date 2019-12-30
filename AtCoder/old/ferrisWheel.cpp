#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;

    if(a<=5){
        cout << 0 << endl;
        return 0;
    }
    if(a<=12){
        cout << b/2 << endl;
        return 0;
    }
    cout << b << endl;
}