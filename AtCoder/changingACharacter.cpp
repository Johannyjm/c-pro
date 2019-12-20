#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i){
        if(i == k - 1) {
            char c = s[i] + 0x20;
            cout << c;
        }
        else cout << s[i];
    }
    cout << endl;

}