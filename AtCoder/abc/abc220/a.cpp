#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    for(int i = a; i <= b; ++i){
        if(i % c == 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}