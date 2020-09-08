#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int h = n/3600;
    n -= 3600*h;
    int m = n/60;
    int s = n%60;

    if(h/10) cout << h;
    else cout << 0 << h;

    cout << ':';

    if(m/10) cout << m;
    else cout << 0 << m;

    cout << ':';    

    if(s/10) cout << s << endl;
    else cout << 0 << s << endl;
}