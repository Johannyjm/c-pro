#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A;
    cin >> N >> A;

    bool flg = N % 500 <= A;

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}