#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n){
        string s;
        cin >> s;

        ++mp[s];
    }

    cout << "AC x " << mp["AC"] << endl;
    cout << "WA x " << mp["WA"] << endl;
    cout << "TLE x " << mp["TLE"] << endl;
    cout << "RE x " << mp["RE"] << endl;
    

    return 0;
}