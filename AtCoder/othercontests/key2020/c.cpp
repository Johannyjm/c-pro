#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {

    int n, k, s;
    cin >> n >> k >> s;

    if(s!=1000000000){
        rep(i, k) cout << s << " ";
        rep(i, n-k) cout << 1000000000 << " "; 
        cout << endl;
    }
    else {
        rep(i, k) cout << 1000000000 << " ";
        rep(i, n-k) cout << 1 << " ";
        cout << endl;
    }

    return 0;
}