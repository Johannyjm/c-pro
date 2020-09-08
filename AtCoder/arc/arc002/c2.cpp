#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const string button[] = {"A", "B", "X", "Y"};
    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = n;
    rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4){
        if(i==k && j==l) continue;
        string L = button[i] + button[j];
        string R = button[k] + button[l];

        int ptr = 0;
        int cnt = 0;
        while(ptr<n){
            if(ptr==n-1) {
                ++cnt;
                ++ptr;
            }
            
            else{
                string tw = s.substr(ptr, 2);
                if(tw==L || tw==R){
                    ++cnt;
                    ptr += 2;
                }

                else{
                    ++cnt;
                    ++ptr;
                }
            }
        }

        res = min(res, cnt);
    }

    cout << res << endl;

    return 0;
}