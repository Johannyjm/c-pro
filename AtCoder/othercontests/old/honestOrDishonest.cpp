#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    char a, b;
    cin >> a >> b;

    if(a == 'H') cout << b << endl;
    else if(b == 'H') cout << 'D' <<endl;
    else cout << 'H' << endl;
}