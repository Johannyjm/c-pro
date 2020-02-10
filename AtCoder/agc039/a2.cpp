#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    ll k;
    cin >> s >> k;
    int remain = 0;

    ll over = 0;
    rep(i, s.size()-1){
        if(s[i]==s[i+1]){
            ++over;
            s[i+1] = '0';
        }
    }
    if(s[0]==s[s.size()-1]){
        ++over;
        ++remain;
    }
    cout << k*over - remain << endl;

    return 0;
}