#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if((A + B + C + D) % 4 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}