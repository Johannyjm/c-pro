#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int a_idx, z_idx;

    for(int i = 0; i < s.length(); ++i){

        if(s[i] == 'A'){
            a_idx = i;
            break;
        }
    }

    for(int i = s.length() - 1; i >= 0; --i){

        if(s[i] == 'Z'){
            z_idx = i;
            break;
        }
    }

    cout << z_idx - a_idx + 1 << endl;
}