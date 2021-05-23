#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    for(auto c: s){
        if(c=='9') cout << '6';
        else if(c=='6') cout << '9';
        else cout << c;
    }
    cout << endl;

    return 0;
}