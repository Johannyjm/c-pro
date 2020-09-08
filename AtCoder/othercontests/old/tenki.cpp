#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int res = 0;
    for (int i = 0; i < 3; ++i){
        if(s[i] == t[i]) res++;
    }
    cout << res << endl;
}