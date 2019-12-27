#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(a%3==0 || b%3==0 || (a+b)%3==0) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}