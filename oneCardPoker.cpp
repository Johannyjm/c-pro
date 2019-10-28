#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    if(A == B) cout << "Draw" << endl;
    else if(A == 1) cout << "Alice" << endl;
    else if(B == 1) cout << "Bob" << endl;
    else cout << ((A > B) ? "Alice": "Bob") << endl;

}