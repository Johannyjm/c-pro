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
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    int max_idx = 0;
    int max_value = -1;
    rep(i, n){
        int idx = s[i] - 'a';
        ++freq[idx];
        if(freq[idx]>max_value) {
            max_value = freq[idx];
            max_idx = idx;
        }
    }

    int m = n - max_value;
    



    return 0;
}