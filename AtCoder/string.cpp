#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s = "test";

    reverse(s.begin(), s.end());

    cout << s << endl;

    // string a = "a";
    // string b = "b";

    // string d = (char)a+1;
    // cout << d << endl;

    char a = 'a';
    char b = 'b';

    cout << max(a, b) << endl;

    // string c = a + b;

    // cout << c << endl;


    return 0;
}