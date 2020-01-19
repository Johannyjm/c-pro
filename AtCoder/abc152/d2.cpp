#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int d(int n){
    int d = 1;
    int tmp = n;
    while(tmp/10){
        ++d;
        tmp/=10;
    }
    return d;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int de = d(n);
    cout << de << endl;


    return 0;
}