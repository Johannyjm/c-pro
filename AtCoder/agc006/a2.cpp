#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int overlap = 0;
    int ptr = 0;
    rep(i, n){
        if(s[i] == t[ptr]){
            ++overlap;
            ++ptr;
        }
        else{
            overlap = 0;
            ptr = 0;
            if(s[i]==t[ptr]){
                ++overlap;
                ++ptr;
            }
        }
    }
    cout << 2*n - overlap << endl;

    return 0;
}