#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << max(A * B, C * D) << endl;
}