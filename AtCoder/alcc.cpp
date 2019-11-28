#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int zero = 0;
    int one = 0;

    for (int i = 0; i < s.size(); ++i){
        char c = s[i];
        if (c == '0') zero++;
        else one++;
    }
    cout << min(zero, one) * 2 << endl;
}