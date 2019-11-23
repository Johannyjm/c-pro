#include <bits/stdc++.h>
using namespace std;

int calcHappiness(string s, int n){
    int res = 0;
    char prev = s[0];

    for(int i = 1; i < n; ++i){
        if(prev == s[i]) res++;
        prev = s[i];
    }
    return res;
}

string procString(string s, int n, int l, int r){
    string res = s;
    for (int i = l; i <= r; ++i){
        if(s[r+l-i] == 'L') res[i] = 'R';
        else res[i] = 'L';
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    // cout << s << endl;
    // cout << calcHappiness(s, n) << endl;
    // string procS = procString(s, n, 1, 4);
    // cout << procS << endl;
    // cout << calcHappiness(procS, n) << endl;

    int res = calcHappiness(s, n);
    for (int l = 0; l < n-1; ++l){
        for (int r = l+1; r < n; ++r){
            string procS = procString(s, n, l, r);
            res = max(res, calcHappiness(procS, n));
            cout << procS << endl;
            cout << res << endl;
        }
    }
    cout << res << endl;

}