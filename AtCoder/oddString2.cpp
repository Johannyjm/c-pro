#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i){
        if(i%2==0)cout << s[i];
    }
    cout << endl;
}