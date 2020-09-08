#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int d(int num){
    int res = 0;
    while(num){
        num /= 10;
        ++res;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int res = pow(10, d(b)) * a + b;
    cout << res*2 << endl; 

}