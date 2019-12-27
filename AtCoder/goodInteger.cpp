#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int d, c, b, a;
    a = n%10;
    n /= 10;

    b = n%10;
    n /= 10;

    c = n%10;
    n /= 10;

    d = n%10;
    
    if((a==b && b==c) || (b==c && c==d)) cout << "Yes" << endl;
    else cout << "No" << endl;
}