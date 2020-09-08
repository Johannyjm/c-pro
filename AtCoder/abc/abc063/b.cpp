#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int bucket[26] = {0};

    rep(i, s.length()){
        ++bucket[s[i] - 'a'];
    }
    rep(i, 26){
        if(bucket[i] > 1){
            puts("no");
            return 0;
        }
    }
    puts("yes");
    return 0;
}