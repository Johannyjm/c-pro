#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;

    n %= int(s.size());
    if(n == 0) n = int(s.size());
    cout << s[n-1] << endl;

    return 0;
}