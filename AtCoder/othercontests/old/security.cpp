#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    char prev = s[0];
    for (int i = 1; i < 4; ++i){
        if(prev == s[i]){
            cout << "Bad" << endl;
            return 0;
        }
        prev = s[i];
    }
    cout << "Good" << endl;
}