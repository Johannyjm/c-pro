#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int num010 = 0;
    int n = s.size();
    rep(i, n){
        char num = '0' + i%2; //char 01010101...
        if(s[i] == num) ++num010;
    }

    cout << min(num010, n-num010) << endl;
}