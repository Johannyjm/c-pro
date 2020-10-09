#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, t;
    cin >> a >> b >> t;

    int T = b-a;
    while(b < t) b += T;

    cout << b << endl;

    return 0;
}