#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int W, a, b;
    cin >> W >> a >> b;

    if((a < b and a + W >= b) or (b < a and b + W >= a)) cout << 0 << endl;
    else cout << min(abs(a + W - b), abs(b + W - a)) << endl;
}