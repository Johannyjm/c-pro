#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    reverse(s.begin(), s.end());

    int even = 0;
    int odd = 0;
    rep(i, n){
        if(i%2 == 0) odd += s[i] - '0';
        else even += s[i] - '0';
    }

    cout << even << " " << odd << endl;

    return 0;
}