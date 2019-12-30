#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int year = 0;
    rep(i, 4) year += (s.substr(0, 4)[i] - '0') * 1000 / pow(10,i);
    int month = 0;
    month = (s.substr(5, 2)[0] - '0') * 10 + s.substr(5, 2)[1] - '0';

    if(year > 2019 || (year == 2019 && month <= 4)) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}