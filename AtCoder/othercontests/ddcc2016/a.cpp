#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w;
    cin >> w;

    string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    int n = s.size();

    int ptr = 0;
    while(ptr < n){
        rep(i, min(n-ptr+1, w)) cout << s[i+ptr];
        cout << endl;
        ptr += w;
    }

    return 0;
}