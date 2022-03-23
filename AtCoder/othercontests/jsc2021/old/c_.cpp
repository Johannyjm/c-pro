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

    rep(i, 10){
        string now = "";
        rep(j, i) now += '0';
        now += s;

        cout << now << endl;
    }

    return 0;
}