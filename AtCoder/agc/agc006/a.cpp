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
    if(s==t) overlap = n;
    else{
        rep(i, n){
            string s_sub = s.substr(n-i-1, i+1);
            string t_sub = t.substr(0, i+1);

            cout << s_sub << " " << t_sub << endl;

            if(s_sub==t_sub) ++overlap;
            else break;
        }
    }

    cout << 2*n - overlap << endl;

    return 0;
}