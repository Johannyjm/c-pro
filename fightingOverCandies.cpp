#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    if(a == b + c or b == c + a or c == a + b) cout << "Yes" << endl;
    else cout << "No" << endl;
}