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

    string s;
    cin >> s;

    map<string, int> freq;
    rep1(i, n){
        string two = s.substr(i-1, 2);
        ++freq[two];
    }

    int fir = -1;
    int sec = -1;
    for(auto f: freq){
        cout << f.first << " " << f.second << endl;
        if(f.second > fir){
            sec = fir;
            fir = f.second;
        }
    }

    cout << fir << " " << sec << endl;

    cout << n - fir - sec << endl;

    return 0;
}