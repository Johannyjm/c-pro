#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;

    for(int i = 1; i*i*i*i <= x; ++i){
        if(i*i*i*i == x){
            cout << i << endl;
            return 0;
        }
    }
}