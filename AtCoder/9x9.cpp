#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    if(A >= 10 or B >= 10) cout << -1 << endl;
    else cout << A * B << endl;
}