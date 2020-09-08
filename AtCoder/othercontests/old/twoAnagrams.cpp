#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());
    
    bool flg = s < t;

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}