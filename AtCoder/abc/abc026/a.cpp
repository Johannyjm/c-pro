#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int n;
    cin >> s >> n;

    cout << s[n/5-(n%5==0)];
    cout << s[n%5+5*(n%5==0)-1] << endl;
}