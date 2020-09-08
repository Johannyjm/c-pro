#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        cout << "No" << endl;
        return 0;
    }

    if(s[0] == s[1]){
        if(s[2] == s[3]){
            cout << "Yes" << endl;
            return 0;
        }
        else cout << "No" << endl;
        return 0;
    }

    if(s[0] == s[2]){
        if(s[1] == s[3]){
            cout << "Yes" << endl;
            return 0;
        }
        else cout << "No" << endl;
        return 0;
    }

    if(s[1] == s[2]){
        if(s[0] == s[3]){
            cout << "Yes" << endl;
            return 0;
        }
        else cout << "No" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}