#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    if(n % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < (n / 2); ++i){
        if(s[i] != s[n / 2 + i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes\n"

}