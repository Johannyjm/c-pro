#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    char c1 = s1[0]-'a'+'A';
    char c2 = s2[0]-'a'+'A';
    char c3 = s3[0]-'a'+'A';

    cout << c1 << c2 << c3 << endl;
}