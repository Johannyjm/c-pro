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
 
    if(s.size()%2){
        s += s;
        remain = k%2;
        k /= 2;
    }
 
    ll over = 0;
    rep(i, s.size()-1){
        if(s[i]==s[i+1]){
            ++over;
            s[i+1] = '0';
        }
    }

    cout << s.size() << endl;
    rep(i, s.size()) cout << s[i];
    cout << endl;
    cout << over << " " << k << " " << remain << endl;
 
    cout << over*k + remain*over/2 << endl;
 
    return 0;
}